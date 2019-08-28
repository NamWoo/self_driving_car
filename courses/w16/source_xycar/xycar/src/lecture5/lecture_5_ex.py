#!/usr/bin/env python

import cv2, time
import numpy as np

cap = cv2.VideoCapture('1.avi')

brightness = 60

width = 640
height = 480

rec_width = 20
rec_height = 10

lpos_offset = rpos_offset = 320
line_height_offset = 15 
thresh_line_pixel_cnt = 150

while(cap.isOpened()):
	ret, frame = cap.read()

	if cv2.waitKey(1) & 0xFF == 27:
		break

	if not ret:
		continue

	roi_frame = frame[430:450, 0:width]
	roi_hsv = cv2.cvtColor(roi_frame, cv2.COLOR_BGR2HSV) 
	
	lower_white = np.array([0,0,brightness], dtype=np.uint8)
	upper_white = np.array([131,255,255], dtype=np.uint8)
   
	hsv_line = cv2.inRange(roi_hsv, lower_white, upper_white)    
	view = cv2.cvtColor(hsv_line, cv2.COLOR_GRAY2BGR)

	rpos = lpos = 0
	
	for lcol in range(lpos_offset, 0, -1):
		detect_area = hsv_line[line_height_offset - rec_height : line_height_offset, (lcol - 1) - rec_width : (lcol - 1)] 
		nonzero = cv2.countNonZero(detect_area)

		if nonzero > thresh_line_pixel_cnt:
			lpos = (lcol - 1)
			break

	for rcol in range(rpos_offset, 640):
		detect_area = hsv_line[line_height_offset - rec_height : line_height_offset, (rcol - 1) : (rcol - 1) + rec_width]
		nonzero = cv2.countNonZero(detect_area)

		if nonzero > thresh_line_pixel_cnt:
			rpos = (rcol - 1)
			break

	detect_area = hsv_line[2:15,120:520]
	cntzero = cv2.countNonZero(detect_area)

	if cntzero > 2400:
		for x in range(120, 520):
			for y in range(0,20):
				if hsv_line[y,x] == 255:
					view[y,x] = [0,255,0]

	left_sq = cv2.rectangle(view, (lpos - rec_width, line_height_offset - rec_height),(lpos, line_height_offset),(0,255,0), 3)
	right_sq = cv2.rectangle(view, (rpos, line_height_offset - rec_height),(rpos + rec_width, line_height_offset),(0,255,0), 3)

	cv2.imshow("origin", frame)
	cv2.imshow("view", view)
	
	time.sleep(0.01)
		
cap.release()
cv2.destroyAllWindows()

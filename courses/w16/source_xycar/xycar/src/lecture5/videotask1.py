import cv2

capture = cv2.VideoCapture("1.avi")

while True:
  #ret : result frame capture
  #frame : capture frame 
  ret, frame = capture.read()
  width = frame.width()

  if (ret):
    #image -> Grey

    roi_frame = frame[430:450, 0:width];
    gray = cv2.cvtColor(roi_frame, cv2.COLOR_BGR2HSV)

    cv2.imshow('frame', gray)
    if cv2.waitKey(1) > 0:
      break

cap.release()
cv2.destroyAllWindows()

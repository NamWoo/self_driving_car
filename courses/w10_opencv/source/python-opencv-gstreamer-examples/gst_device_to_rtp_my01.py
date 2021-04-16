import time
import cv2

def frameProcessing(frame):
    result = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    return result


# Cam properties
fps = 30.
frame_width = 1280
frame_height = 720
# Create capture
cap = cv2.VideoCapture(4)   

# Set camera properties
cap.set(cv2.CAP_PROP_FRAME_WIDTH, frame_width)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, frame_height)
cap.set(cv2.CAP_PROP_FPS, fps)

# Define the gstreamer sink
gst_str_rtp = "appsrc ! videoconvert ! x264enc tune=zerolatency bitrate=500 speed-preset=superfast ! rtph264pay ! udpsink host=127.0.0.1 port=5000"



# Check if cap is open
if cap.isOpened() is not True:
    print "Cannot open camera. Exiting."
    quit()

# Create videowriter as a SHM sink
fourcc = int(cv2.VideoWriter_fourcc(*'video/x-h264'))
out = cv2.VideoWriter(gst_str_rtp, fourcc, fps, (frame_width, frame_height), True)

# # Loop it
# while True:
#     # Get the frame
#     ret, frame = cap.read()
#     # Check
#     if ret is True:
#         # Flip frame
#         frame = cv2.flip(frame, 1)
#         # Write to SHM
#         out.write(frame)
#     else:
#         print "Camera error."
#         break

# cap.release()

while cap.isOpened():
    # Capture frame-by-frame
    ret, frame = cap.read()

    if ret:
        # Our operations on the frame come here
        output = frameProcessing(frame)
        # frame = cv2.flip(frame, 1)
        # Write frame-by-frame
        out.write(frame)
        # Display the resulting frame
        # cv2.imshow("Input", frame)
        # cv2.imshow("Output", out)

    else:
        break

    # waitKey(int(1000.0/fps)) for matching fps of video
    if cv2.waitKey(int(1000.0/fps)) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap.release()
out.release()
cv2.destroyAllWindows()
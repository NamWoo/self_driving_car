from multiprocessing import Process
import cv2

def send():
    cap_send = cv2.VideoCapture('videotestsrc ! video/x-H64,framerate=20/1 ! videoscale ! videoconvert ! appsink', cv2.CAP_GSTREAMER)
    out_send = cv2.VideoWriter('appsrc ! videoconvert ! x264enc tune=zerolatency bitrate=500 speed-preset=superfast \
                                ! rtph264pay ! udpsink host=127.0.0.1 port=5000',cv2.CAP_GSTREAMER,0, 30, (1280,720), True)


# $ gst-launch-1.0 -v -e v4l2src device=/dev/video1 ! queue ! video/x-h264,width=1280,height=720,framerate=30/1 ! 
#       h264parse ! avdec_h264 ! xvimagesink sync=false


    if not cap_send.isOpened() or not out_send.isOpened():
        print('VideoCapture or VideoWriter not opened')
        exit(0)

    while True:
        ret,frame = cap_send.read()

        if not ret:
            print('empty frame')
            break

        out_send.write(frame)

        cv2.imshow('send', frame)
        if cv2.waitKey(1)&0xFF == ord('q'):
            break

    cap_send.release()
    out_send.release()

def receive():
    cap_receive = cv2.VideoCapture('udpsrc port=5000 caps = "application/x-rtp, media=(string)video, clock-rate=(int)90000, encoding-name=(string)H264, payload=(int)96" ! rtph264depay ! decodebin ! videoconvert ! appsink', cv2.CAP_GSTREAMER)

    if not cap_receive.isOpened():
        print('VideoCapture not opened')
        exit(0)

    while True:
        ret,frame = cap_receive.read()

        if not ret:
            print('empty frame')
            break

        cv2.imshow('receive', frame)
        if cv2.waitKey(1)&0xFF == ord('q'):
            break

    #cap_receive.release()

if __name__ == '__main__':
    s = Process(target=send)
    r = Process(target=receive)
    s.start()
    r.start()
    s.join()
    r.join()

    cv2.destroyAllWindows()
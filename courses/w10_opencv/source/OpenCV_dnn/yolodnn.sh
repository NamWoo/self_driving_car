#!/bin/bash
./yolo_object_detection -source=output_LaneDetection_Project.avi -cfg=yolov2-tiny.cfg -model=yolov2-tiny.weights   -class_names=coco.names

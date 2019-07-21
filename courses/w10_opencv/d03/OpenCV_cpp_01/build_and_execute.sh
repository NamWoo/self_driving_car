#!/bin/bash
g++ TEST_OpenCV.cpp -o out.o $(pkg-config opencv --cflags --libs)

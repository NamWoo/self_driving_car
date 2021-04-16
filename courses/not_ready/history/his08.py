  739  [shortcut]
  740  from=-3
  741  activation=linear
  742  [convolutional]
  743  batch_normalize=1
  744  filters=64
  745  size=1
  746  stride=1
  747  pad=1
  748  activation=leaky
  749  [convolutional]
  750  batch_normalize=1
  751  filters=128
  752  size=3
  753  stride=1
  754  pad=1
  755  activation=leaky
  756  [shortcut]
  757  from=-3
  758  activation=linear
  759  # Downsample
  760  [convolutional]
  761  batch_normalize=1
  762  filters=256
  763  size=3
  764  stride=2
  765  pad=1
  766  activation=leaky
  767  [convolutional]
  768  batch_normalize=1
  769  filters=128
  770  size=1
  771  stride=1
  772  pad=1
  773  activation=leaky
  774  [convolutional]
  775  batch_normalize=1
  776  filters=256
  777  size=3
  778  stride=1
  779  pad=1
  780  activation=leaky
  781  [shortcut]
  782  from=-3
  783  activation=linear
  784  [convolutional]
  785  batch_normalize=1
  786  filters=128
  787  size=1
  788  stride=1
  789  pad=1
  790  activation=leaky
  791  [convolutional]
  792  batch_normalize=1
  793  filters=256
  794  size=3
  795  stride=1
  796  pad=1
  797  activation=leaky
  798  [shortcut]
  799  from=-3
  800  activation=linear
  801  [convolutional]
  802  batch_normalize=1
  803  filters=128
  804  size=1
  805  stride=1
  806  pad=1
  807  activation=leaky
  808  [convolutional]
  809  batch_normalize=1
  810  filters=256
  811  size=3
  812  stride=1
  813  pad=1
  814  activation=leaky
  815  [shortcut]
  816  from=-3
  817  activation=linear
  818  [convolutional]
  819  batch_normalize=1
  820  filters=128
  821  size=1
  822  stride=1
  823  pad=1
  824  activation=leaky
  825  [convolutional]
  826  batch_normalize=1
  827  filters=256
  828  size=3
  829  stride=1
  830  pad=1
  831  activation=leaky
  832  [shortcut]
  833  from=-3
  834  activation=linear
  835  [convolutional]
  836  batch_normalize=1
  837  filters=128
  838  size=1
  839  stride=1
  840  pad=1
  841  activation=leaky
  842  [convolutional]
  843  batch_normalize=1
  844  filters=256
  845  size=3
  846  stride=1
  847  pad=1
  848  activation=leaky
  849  [shortcut]
  850  from=-3
  851  activation=linear
  852  [convolutional]
  853  batch_normalize=1
  854  filters=128
  855  size=1
  856  stride=1
  857  pad=1
  858  activation=leaky
  859  [convolutional]
  860  batch_normalize=1
  861  filters=256
  862  size=3
  863  stride=1
  864  pad=1
  865  activation=leaky
  866  [shortcut]
  867  from=-3
  868  activation=linear
  869  [convolutional]
  870  batch_normalize=1
  871  filters=128
  872  size=1
  873  stride=1
  874  pad=1
  875  activation=leaky
  876  [convolutional]
  877  batch_normalize=1
  878  filters=256
  879  size=3
  880  stride=1
  881  pad=1
  882  activation=leaky
  883  [shortcut]
  884  from=-3
  885  activation=linear
  886  [convolutional]
  887  batch_normalize=1
  888  filters=128
  889  size=1
  890  stride=1
  891  pad=1
  892  activation=leaky
  893  [convolutional]
  894  batch_normalize=1
  895  filters=256
  896  size=3
  897  stride=1
  898  pad=1
  899  activation=leaky
  900  [shortcut]
  901  from=-3
  902  activation=linear
  903  # Downsample
  904  [convolutional]
  905  batch_normalize=1
  906  filters=512
  907  size=3
  908  stride=2
  909  pad=1
  910  activation=leaky
  911  [convolutional]
  912  batch_normalize=1
  913  filters=256
  914  size=1
  915  stride=1
  916  pad=1
  917  activation=leaky
  918  [convolutional]
  919  batch_normalize=1
  920  filters=512
  921  size=3
  922  stride=1
  923  pad=1
  924  activation=leaky
  925  [shortcut]
  926  from=-3
  927  activation=linear
  928  [convolutional]
  929  batch_normalize=1
  930  filters=256
  931  size=1
  932  stride=1
  933  pad=1
  934  activation=leaky
  935  [convolutional]
  936  batch_normalize=1
  937  filters=512
  938  size=3
  939  stride=1
  940  pad=1
  941  activation=leaky
  942  [shortcut]
  943  from=-3
  944  activation=linear
  945  [convolutional]
  946  batch_normalize=1
  947  filters=256
  948  size=1
  949  stride=1
  950  pad=1
  951  activation=leaky
  952  [convolutional]
  953  batch_normalize=1
  954  filters=512
  955  size=3
  956  stride=1
  957  pad=1
  958  activation=leaky
  959  [shortcut]
  960  from=-3
  961  activation=linear
  962  [convolutional]
  963  batch_normalize=1
  964  filters=256
  965  size=1
  966  stride=1
  967  pad=1
  968  activation=leaky
  969  [convolutional]
  970  batch_normalize=1
  971  filters=512
  972  size=3
  973  stride=1
  974  pad=1
  975  activation=leaky
  976  [shortcut]
  977  from=-3
  978  activation=linear
  979  [convolutional]
  980  batch_normalize=1
  981  filters=256
  982  size=1
  983  stride=1
  984  pad=1
  985  activation=leaky
  986  [convolutional]
  987  batch_normalize=1
  988  filters=512
  989  size=3
  990  stride=1
  991  pad=1
  992  activation=leaky
  993  [shortcut]
  994  from=-3
  995  activation=linear
  996  [convolutional]
  997  batch_normalize=1
  998  filters=256
  999  size=1
 1000  stride=1
 1001  pad=1
 1002  activation=leaky
 1003  [convolutional]
 1004  batch_normalize=1
 1005  filters=512
 1006  size=3
 1007  stride=1
 1008  pad=1
 1009  activation=leaky
 1010  [shortcut]
 1011  from=-3
 1012  activation=linear
 1013  [convolutional]
 1014  batch_normalize=1
 1015  filters=256
 1016  size=1
 1017  stride=1
 1018  pad=1
 1019  activation=leaky
 1020  [convolutional]
 1021  batch_normalize=1
 1022  filters=512
 1023  size=3
 1024  stride=1
 1025  pad=1
 1026  activation=leaky
 1027  [shortcut]
 1028  from=-3
 1029  activation=linear
 1030  [convolutional]
 1031  batch_normalize=1
 1032  filters=256
 1033  size=1
 1034  stride=1
 1035  pad=1
 1036  activation=leaky
 1037  [convolutional]
 1038  batch_normalize=1
 1039  filters=512
 1040  size=3
 1041  stride=1
 1042  pad=1
 1043  activation=leaky
 1044  [shortcut]
 1045  from=-3
 1046  activation=linear
 1047  # Downsample
 1048  [convolutional]
 1049  batch_normalize=1
 1050  filters=1024
 1051  size=3
 1052  stride=2
 1053  pad=1
 1054  activation=leaky
 1055  [convolutional]
 1056  batch_normalize=1
 1057  filters=512
 1058  size=1
 1059  stride=1
 1060  pad=1
 1061  activation=leaky
 1062  [convolutional]
 1063  batch_normalize=1
 1064  filters=1024
 1065  size=3
 1066  stride=1
 1067  pad=1
 1068  activation=leaky
 1069  [shortcut]
 1070  from=-3
 1071  activation=linear
 1072  [convolutional]
 1073  batch_normalize=1
 1074  filters=512
 1075  size=1
 1076  stride=1
 1077  pad=1
 1078  activation=leaky
 1079  [convolutional]
 1080  batch_normalize=1
 1081  filters=1024
 1082  size=3
 1083  stride=1
 1084  pad=1
 1085  activation=leaky
 1086  [shortcut]
 1087  from=-3
 1088  activation=linear
 1089  [convolutional]
 1090  batch_normalize=1
 1091  filters=512
 1092  size=1
 1093  stride=1
 1094  pad=1
 1095  activation=leaky
 1096  [convolutional]
 1097  batch_normalize=1
 1098  filters=1024
 1099  size=3
 1100  stride=1
 1101  pad=1
 1102  activation=leaky
 1103  [shortcut]
 1104  from=-3
 1105  activation=linear
 1106  [convolutional]
 1107  batch_normalize=1
 1108  filters=512
 1109  size=1
 1110  stride=1
 1111  pad=1
 1112  activation=leaky
 1113  [convolutional]
 1114  batch_normalize=1
 1115  filters=1024
 1116  size=3
 1117  stride=1
 1118  pad=1
 1119  activation=leaky
 1120  [shortcut]
 1121  from=-3
 1122  activation=linear
 1123  ######################
 1124  [convolutional]
 1125  batch_normalize=1
 1126  filters=512
 1127  size=1
 1128  stride=1
 1129  pad=1
 1130  activation=leaky
 1131  [convolutional]
 1132  batch_normalize=1
 1133  size=3
 1134  stride=1
 1135  pad=1
 1136  filters=1024
 1137  activation=leaky
 1138  [convolutional]
 1139  batch_normalize=1
 1140  filters=512
 1141  size=1
 1142  stride=1
 1143  pad=1
 1144  activation=leaky
 1145  [convolutional]
 1146  batch_normalize=1
 1147  size=3
 1148  stride=1
 1149  pad=1
 1150  filters=1024
 1151  activation=leaky
 1152  [convolutional]
 1153  batch_normalize=1
 1154  filters=512
 1155  size=1
 1156  stride=1
 1157  pad=1
 1158  activation=leaky
 1159  [convolutional]
 1160  batch_normalize=1
 1161  size=3
 1162  stride=1
 1163  pad=1
 1164  filters=1024
 1165  activation=leaky
 1166  [convolutional]
 1167  size=1
 1168  stride=1
 1169  pad=1
 1170  filters=255
 1171  activation=linear
 1172  [yolo]
 1173  mask = 6,7,8
 1174  anchors = 10,13,  16,30,  33,23,  30,61,  62,45,  59,119,  116,90,  156,198,  373,326
 1175  classes=80
 1176  num=9
 1177  jitter=.3
 1178  ignore_thresh = .7
 1179  truth_thresh = 1
 1180  random=1
 1181  [route]
 1182  layers = -4
 1183  [convolutional]
 1184  batch_normalize=1
 1185  filters=256
 1186  size=1
 1187  stride=1
 1188  pad=1
 1189  activation=leaky
 1190  [upsample]
 1191  stride=2
 1192  [route]
 1193  layers = -1, 61
 1194  [convolutional]
 1195  batch_normalize=1
 1196  filters=256
 1197  size=1
 1198  stride=1
 1199  pad=1
 1200  activation=leaky
 1201  [convolutional]
 1202  batch_normalize=1
 1203  size=3
 1204  stride=1
 1205  pad=1
 1206  filters=512
 1207  activation=leaky
 1208  [convolutional]
 1209  batch_normalize=1
 1210  filters=256
 1211  size=1
 1212  stride=1
 1213  pad=1
 1214  activation=leaky
 1215  [convolutional]
 1216  batch_normalize=1
 1217  size=3
 1218  stride=1
 1219  pad=1
 1220  filters=512
 1221  activation=leaky
 1222  [convolutional]
 1223  batch_normalize=1
 1224  filters=256
 1225  size=1
 1226  stride=1
 1227  pad=1
 1228  activation=leaky
 1229  [convolutional]
 1230  batch_normalize=1
 1231  size=3
 1232  stride=1
 1233  pad=1
 1234  filters=512
 1235  activation=leaky
 1236  [convolutional]
 1237  size=1
 1238  stride=1
 1239  pad=1
 1240  filters=255
 1241  activation=linear
 1242  [yolo]
 1243  mask = 3,4,5
 1244  anchors = 10,13,  16,30,  33,23,  30,61,  62,45,  59,119,  116,90,  156,198,  373,326
 1245  classes=80
 1246  num=9
 1247  jitter=.3
 1248  ignore_thresh = .7
 1249  truth_thresh = 1
 1250  random=1
 1251  [route]
 1252  layers = -4
 1253  [convolutional]
 1254  batch_normalize=1
 1255  filters=128
 1256  size=1
 1257  stride=1
 1258  pad=1
 1259  activation=leaky
 1260  [upsample]
 1261  stride=2
 1262  [route]
 1263  layers = -1, 36
 1264  [convolutional]
 1265  batch_normalize=1
 1266  filters=128
 1267  size=1
 1268  stride=1
 1269  pad=1
 1270  activation=leaky
 1271  [convolutional]
 1272  batch_normalize=1
 1273  size=3
 1274  stride=1
 1275  pad=1
 1276  filters=256
 1277  activation=leaky
 1278  [convolutional]
 1279  batch_normalize=1
 1280  filters=128
 1281  size=1
 1282  stride=1
 1283  pad=1
 1284  activation=leaky
 1285  [convolutional]
 1286  batch_normalize=1
 1287  size=3
 1288  stride=1
 1289  pad=1
 1290  filters=256
 1291  activation=leaky
 1292  [convolutional]
 1293  batch_normalize=1
 1294  filters=128
 1295  size=1
 1296  stride=1
 1297  pad=1
 1298  activation=leaky
 1299  [convolutional]
 1300  batch_normalize=1
 1301  size=3
 1302  stride=1
 1303  pad=1
 1304  filters=256
 1305  activation=leaky
 1306  [convolutional]
 1307  size=1
 1308  stride=1
 1309  pad=1
 1310  filters=255
 1311  activation=linear
 1312  [yolo]
 1313  mask = 0,1,2
 1314  anchors = 10,13,  16,30,  33,23,  30,61,  62,45,  59,119,  116,90,  156,198,  373,326
 1315  classes=80
 1316  num=9
 1317  jitter=.3
 1318  ignore_thresh = .7
 1319  truth_thresh = 1
 1320  random=1./darknet detector demo cfg/coco.data cfg/yolov3.cfg yolov3.weights                           -c 1
 1321  ./darknet detector demo cfg/coco.data cfg/yolov3.cfg yolov3.weights                           -c 1
 1322  ./darknet detector demo cfg/coco.data cfg/yolov3.cfg yolov3.weights -c 1
 1323  cd ..
 1324  ./darknet detector demo cfg/coco.data cfg/yolov3.cfg yolov3.weights -c 1
 1325  make
 1326  make clean
 1327  vi Makefile 
 1328  make
 1329  ./darknet detector demo cfg/coco.data cfg/yolov3.cfg yolov3.weights -c 1
 1330  vi Makefile 
 1331  cd cfg/
 1332  ls
 1333  cd ..
 1334  ls
 1335  ./darknet detector demo cfg/coco.data cfg/yolov3.cfg yolov3.weights -c 1
 1336  cd ls
 1337  ls
 1338  cd cfg/
 1339  ls
 1340  vi yolov3.cfg 
 1341  cd ..
 1342  make clean && makr
 1343  make clean && make
 1344  ./darknet detector demo cfg/coco.data cfg/yolov3.cfg yolov3.weights -c 1
 1345  cat /etc/nv_tegra_release
 1346  sha1sum -c /etc/nv_tegra_release
 1347  vi yolov3.cfg 
 1348  vi Makefile 
 1349  make clean && make
 1350  vi Makefile 
 1351  make clean && make
 1352  vi Makefile 
 1353  make clean && make
 1354  vi Makefile 
 1355  make clean && make
 1356  vi Makefile 
 1357  make clean && make
 1358  vi Makefile 
 1359  make clean && make
 1360  ./darknet detector demo cfg/coco.data cfg/yolov3.cfg yolov3.weights -c 1
 1361  ls
 1362  cd data/
 1363  ls
 1364  ./darknet detector test cfg/voc.data cfg/yolo-voc.cfg yolo-voc.weights data/dog.jpg
 1365  cd ..
 1366  cd yolov3/
 1367  ./darknet detector test cfg/volo cfg/yolo-voc.cfg yolo-voc.weights data/dog.jp
 1368  ./darknet detector demo cfg/coco.data cfg/yolov3.cfg yolov3.weights data/dog.jpg
 1369  history
 1370  history >> ~/Desktop/his1.py
 1371  cd ..
 1372  vi his1.py 
 1373  sudo shutdown -h now
 1374  sudo ./jetson_clocks.sh 
 1375  ll
 1376  ./tegrastats 
 1377  cd ~/Desktop/ls
 1378  cd ~/Desktop/
 1379  ls
 1380  cd OpenCV_Jetson_nano/
 1381  l
 1382  cd darknet/
 1383  l
 1384  make
 1385  wget https://pjreddie.com/media/files/yolov3.weights
 1386  ./darknet detect cfg/yolov3.cfg yolov3.weights data/dog.jpg
 1387  ls
 1388  ./darknet detect cfg/yolov3.cfg yolov3.weights -c 0
 1389  wget https://pjreddie.com/media/files/yolov3-tiny.weights
 1390  ./darknet detect cfg/yolov3-tiny.cfg yolov3-tiny.weights data/dog.jpg
 1391  ./darknet detector demo cfg/coco.data cfg/yolov3.cfg yolov3.weights
 1392  ./darknet detector demo cfg/coco.data cfg/yolov3.cfg yolov3.weights -c 1
 1393  make
 1394  vi Makefile 
 1395  make
 1396  ./darknet detector demo cfg/coco.data cfg/yolov3.cfg yolov3.weights -c 1
 1397  vi Makefile 
 1398  ls
 1399  history
 1400  ;s
 1401  ls
 1402  cd ..
 1403  ls
 1404  vi Makefile 
 1405  ls
 1406  vi darknet_fp16_yolov3_320.sh 
 1407  vi INSTALL.sh 
 1408  vi darknet
 1409  cd darknet/
 1410  l
 1411  vi build.sh 
 1412  cd vb
 1413  cd b 
 1414  cd build/
 1415  l
 1416  cd darknet/
 1417  l
 1418  cd x64/
 1419  l
 1420  cd ..
 1421  cd ../..
 1422  ./darknet detector demo cfg/coco.data cfg/yolov3.cfg yolov3.weights -c 1
 1423  ls
 1424  ./darknet detector demo cfg/coco.data cfg/yolov3-tiny.cfg yolov3-tiny.weights -c 1
 1425  sudo shutdown -h now
 1426  l
 1427  shitory
 1428  history
 1429  history >> ./Desktop/hisjetson01.py
 1430  sudo apt-add-repository ppa:sylvain-pineau/kazam
 1431  sudo apt-get update
 1432  sudo apt-get install kazam
 1433  kazam
 1434  cd ~/Desktop/
 1435  ls
 1436  cd OpenCV_Jetson_nano/
 1437  ls
 1438  ll
 1439  v412-ct1-V
 1440  v412-ct1 -V
 1441  cd ~/dE
 1442  cd ~/Desktop/
 1443  vi w12d04_gym01.py 
 1444  sudo apt-get install libav-tools 
 1445  history
 1446  sudo -H pip install keras==1.0.2
 1447  sudo -H pup install gym==0.9.1
 1448  sudo -H pip install gym==0.9.1
 1449  cd ~/Desktop/
 1450  ks
 1451  ls
 1452  vi w12d04_gym01.py
 1453  python w12d04_gym01.py 
 1454  vi w12d04_gym01.py 
 1455  python3 w12d04_gym01.py 
 1456  python2 w12d04_gym01.py 
 1457  python w12d04_gym01.py 
 1458  python2 w12d04_gym01.py 
 1459  python2
 1460  python w12d04_gym01.py
 1461  python w12d04_gym01.py 
 1462  cat /etc/nv_tegra_release 
 1463  head -n 1 /etc/nv_tegra_release
 1464  cd ~/Desktop/
 1465  ls
 1466  git clone https://github.com/jetsonhacks/installROSTX1
 1467  cd installROSTX1/
 1468  l
 1469  ./installROS.sh 
 1470  sudo ./installROS.sh
 1471  vi ./installROS.sh
 1472  c ..
 1473  cd ..
 1474  vi bong1.sh
 1475  chmod u+x bong1.sh 
 1476  ./bong1.sh 
 1477  vi bong1.sh
 1478  cd ~/catkin_ws/]
 1479  ls
 1480  vi bong1.sh
 1481  ls
 1482  vi darknet_fp16_yolov3_320.sh 
 1483  ./darknet_fp16_yolov3_320.sh 
 1484  vi darknet_fp16_yolov3_320.sh 
 1485  cd ~/
 1486  mkdir catkin_ws
 1487  cd catkin_ws/
 1488  mkdir src
 1489  ls
 1490  cd src/
 1491  ls
 1492  $ cd ~/catkin_ws/src
 1493  $ git clone https://github.com/dusty-nv/ros_deep_learning
 1494  $ cd ../
 1495  git clone https://github.com/dusty-nv/ros_deep_learning
 1496  ls
 1497  cd ..
 1498  catkin_make
 1499  vi ~/.bashrc
 1500  cd ~/catkin_ws/
 1501  catkin_make
 1502  sudo apt-get update
 1503  sudo apt-get install libglew-dev glew-utils libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libglib2.0-dev
 1504  sudo apt-get install cmake
 1505  cd catkin_ws/
 1506  catkin_make
 1507  cd src/
 1508  ls
 1509  cd ros_deep_learning/
 1510  ls
 1511  cd ..
 1512  git clonehttps://github.com/dusty-nv/jetson-utils
 1513  git clone https://github.com/dusty-nv/jetson-utils
 1514  cd ..
 1515  catkin_make
 1516  cd src/
 1517  ls
 1518  cd ros_deep_learning/
 1519  ls
 1520  vi CMakeLists.txt 
 1521  cd ../..
 1522  ls
 1523  catkin_init_workspace
 1524  ls
 1525  catkin_make
 1526  cd ~/Desktop/
 1527  ls
 1528  git clone https://github.com/jetsonhacks
 1529  git clone https://github.com/jetsonhacks/installROSTX1
 1530  ls
 1531  cd installROSTX1/
 1532  ls
 1533  ./setupCatkinWorkspace.sh 
 1534  cd ~/catkin_ws/
 1535  ls
 1536  cd src/
 1537  l
 1538  rm -rf jetson-utils ros_deep_learning/
 1539  ls
 1540  catkin_init_workspace 
 1541  cd ..
 1542  catkin_make
 1543  grep -q -F ' ROS_MASTER_URI' ~/.bashrc ||  echo 'export ROS_MASTER_URI=http://localhost:11311' | tee -a ~/.bashrc
 1544  grep -q -F ' ROS_IP' ~/.bashrc ||  echo "export ROS_IP=$(hostname -I)" | tee -a ~/.bashrc
 1545  echo "export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH" >> ~/.bashrc
 1546  l
 1547  cd ~/catkin_ws/
 1548  ls
 1549  source /opt/ros/kinetic/setup.bash
 1550  catkin_make
 1551  sudo apt-get install git cmake
 1552  cd ~
 1553  git clone https://github.com/dusty-nv/jetson-inference
 1554  cd jetson-inference
 1555  git submodule update --init
 1556  mkdir build
 1557  cd build
 1558  cmake ../
 1559  make
 1560  sudo make install
 1561  cd ~/
 1562  cd ~/Desktop/
 1563  ./installROS.sh -p ros-kinetic-desktop -p ros-kinetic-rgbd-launch
 1564  cd installROSTX1/
 1565  ls
 1566  ./installROS.sh -p ros-kinetic-desktop -p ros-kinetic-rgbd-launch
 1567  cd ~/Desktop/
 1568  cd ~/catkin_ws/
 1569  ls
 1570  cd ..
 1571  rm -rf catkin_ws
 1572  ls
 1573  cd ~/Desktop/installROSTX1/
 1574  ./setupCatkinWorkspace.sh catkin_ws
 1575  cd ~/catkin_ws/src/
 1576  ls
 1577  cd ~/Desktop/
 1578  sudo apt-get install ros-kinetic-image-transport
 1579  sudo apt-get install ros-kinetic-image-publisher
 1580  sudo apt-get install ros-kinetic-vision-msgs
 1581  cd ~/catkin_ws/src/
 1582  ls
 1583  git clone https://github.com/dusty-nv/ros_deep_learning
 1584  cd ../
 1585  ls
 1586  catkin_make
 1587  roscore
 1588  sudo roscore
 1589  cd ..
 1590  wget https://raw.githubusercontent.com/ROBOTIS-GIT/robotis_tools/master/install_ros_kinetic.sh
 1591  ls
 1592  mv install_ros_kinetic.sh ~/Desktop/
 1593  cd ~/Desktop/
 1594  ls
 1595  vi install_ros_kinetic.sh 
 1596  chmod 755 ./install_ros_kinetic.sh 
 1597  sudo bash ./install_ros_kinetic.sh 
 1598  cd ~/catkin_qws/
 1599  ls
 1600  cd src/
 1601  ls
 1602  roscore
 1603  vi ~/install_ros_kinetic.sh 
 1604  cd ~/Desktop/
 1605  ls
 1606  vi install
 1607  vi install_ros_kinetic.sh 
 1608  cd ~/catkin_qws/
 1609  cd src/
 1610  ls
 1611  git clone https://github.com/dusty-nv/ros_deep_learning
 1612  sudo git clone https://github.com/dusty-nv/ros_deep_learning
 1613  ls
 1614  cd ..
 1615  alias
 1616  sb
 1617  vi ~/.bashrc 
 1618  cd ~/catkin_qws/
 1619  catkin_make
 1620  sudo catkin_make
 1621  cd ../catkin_ws
 1622  ls
 1623  cd ..
 1624  rm -rf catkin_ws
 1625  rm -rf catkin_qws
 1626  sudo rm -rf catkin_qws
 1627  ls
 1628  mkdir ~/catkin_ws
 1629  cd ~/catkin_ws/
 1630  mkdir src
 1631  cd src/
 1632  cd ..
 1633  cd src/
 1634  catkin_init_workspace 
 1635  cd ..
 1636  catkin_make
 1637  cd src/
 1638  git clone https://github.com/dusty-nv/ros_deep_learning
 1639  ~/Desktop/
 1640  cd ~/Desktop/
 1641  ls
 1642  vi install_ros_kinetic.sh 
 1643  cd ~/catkin_ws/
 1644  ls
 1645  cd src/
 1646  ;s
 1647  ;
 1648  l
 1649  cd ~/catkin_ws/
 1650  catkin_make
 1651  catkin_make -j4
 1652  catkin_make -l4
 1653  catkin clean
 1654  catkin_clean
 1655  ls
 1656  cd build/
 1657  ls
 1658  cd ..
 1659  ls
 1660  cd src
 1661  ls
 1662  cd ..
 1663  cd devel/
 1664  ls
 1665  cd ..
 1666  ls
 1667  cd devel/
 1668  ls
 1669  vi ~/.bashrc 
 1670  cd ~/catkin_ws/
 1671  ls
 1672  cd src/
 1673  catkin_make
 1674  cd ..
 1675  catkin_make
 1676  df h
 1677  df -h
 1678  roscore
 1679  pip install jupyterlab
 1680  sudo pip install jupyterlab
 1681  jupyter
 1682  jupyter notebook
 1683  cd ~/Desktop/
 1684  cd ../Downloads/
 1685  ls
 1686  vscode
 1687  python3 -m pip install --upgrade pip
 1688  sudo pip install --upgrade pip
 1689  pip3 install jupyterlab
 1690  sudo apt-get install jupyterlab
 1691  pip install pandas
 1692  python3
 1693  apt-get install python3-pip -y
 1694  sudo apt-get install python3-pip -y
 1695  pip3 install --upgrade pip && python3 -m pip install ipykernel && python3 -m ipykernel install --user
 1696  jupyter notebook
 1697  python
 1698  df -f
 1699  df -h
 1700  chromium-browser 
 1701  sudo shutdown -h now
 1702  sudo apt-transport-http libxkbfile-dev libsecret-1-dev rpm
 1703  curl -sL https://deb.nodesource.com/setup_8.x | sudo -E bash -
 1704  sudo apt-get install -y nodejs
 1705  sudo apt-get update
 1706  sudo apt-get install yarn
 1707  cd ~/Desktop/
 1708  git clone --recursive https://github.com/Microsoft/vscode.git
 1709  cd vscode/
 1710  ls
 1711  gedit packages.json
 1712  ls
 1713  vi package.json 
 1714  cd test/
 1715  ls
 1716  cd smoke/
 1717  vi package.json 
 1718  cd ../..
 1719  yarn --arch=arm64
 1720  yarn --arch=arm64 run watch
 1721  yarn add gulp-bom --no-save
 1722  sudo apt-get install fakeroot rpm
 1723  sudo apt-get install libsecret-1-dev.
 1724  sudo yum install libX11-devel.x86_64 libxkbfile-devel.x86_64 # or .i686.
 1725  sudo yum install libX11-devel.x86_64 libxkbfile-devel.x86_64 # or .i686
 1726  sudo apt-get install libx11-dev libxkbfile-dev
 1727  sudo apt-get install libsecret-1-dev
 1728  yarn
 1729  yarn cache clean
 1730  ~/.node-gyp
 1731  cd ~/.node-gyp
 1732  ls
 1733  cd ..
 1734  rm -rf ~/.node-gyp
 1735  cd ~/Desktop/vscode/
 1736  ls
 1737  yarn
 1738  history >> ~/Desktop/his08.py

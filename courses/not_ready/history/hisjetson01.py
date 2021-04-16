  430  batch_normalize=1
  431  filters=512
  432  size=1
  433  stride=1
  434  pad=1
  435  activation=leaky
  436  [convolutional]
  437  batch_normalize=1
  438  filters=1024
  439  size=3
  440  stride=1
  441  pad=1
  442  activation=leaky
  443  [shortcut]
  444  from=-3
  445  activation=linear
  446  [convolutional]
  447  batch_normalize=1
  448  filters=512
  449  size=1
  450  stride=1
  451  pad=1
  452  activation=leaky
  453  [convolutional]
  454  batch_normalize=1
  455  filters=1024
  456  size=3
  457  stride=1
  458  pad=1
  459  activation=leaky
  460  [shortcut]
  461  from=-3
  462  activation=linear
  463  ######################
  464  [convolutional]
  465  batch_normalize=1
  466  filters=512
  467  size=1
  468  stride=1
  469  pad=1
  470  activation=leaky
  471  [convolutional]
  472  batch_normalize=1
  473  size=3
  474  stride=1
  475  pad=1
  476  filters=1024
  477  activation=leaky
  478  [convolutional]
  479  batch_normalize=1
  480  filters=512
  481  size=1
  482  stride=1
  483  pad=1
  484  activation=leaky
  485  [convolutional]
  486  batch_normalize=1
  487  size=3
  488  stride=1
  489  pad=1
  490  filters=1024
  491  activation=leaky
  492  [convolutional]
  493  batch_normalize=1
  494  filters=512
  495  size=1
  496  stride=1
  497  pad=1
  498  activation=leaky
  499  [convolutional]
  500  batch_normalize=1
  501  size=3
  502  stride=1
  503  pad=1
  504  filters=1024
  505  activation=leaky
  506  [convolutional]
  507  size=1
  508  stride=1
  509  pad=1
  510  filters=255
  511  activation=linear
  512  [yolo]
  513  mask = 6,7,8
  514  anchors = 10,13,  16,30,  33,23,  30,61,  62,45,  59,119,  116,90,  156,198,  373,326
  515  classes=80
  516  num=9
  517  jitter=.3
  518  ignore_thresh = .7
  519  truth_thresh = 1
  520  random=1
  521  [route]
  522  layers = -4
  523  [convolutional]
  524  batch_normalize=1
  525  filters=256
  526  size=1
  527  stride=1
  528  pad=1
  529  activation=leaky
  530  [upsample]
  531  stride=2
  532  [route]
  533  layers = -1, 61
  534  [convolutional]
  535  batch_normalize=1
  536  filters=256
  537  size=1
  538  stride=1
  539  pad=1
  540  activation=leaky
  541  [convolutional]
  542  batch_normalize=1
  543  size=3
  544  stride=1
  545  pad=1
  546  filters=512
  547  activation=leaky
  548  [convolutional]
  549  batch_normalize=1
  550  filters=256
  551  size=1
  552  stride=1
  553  pad=1
  554  activation=leaky
  555  [convolutional]
  556  batch_normalize=1
  557  size=3
  558  stride=1
  559  pad=1
  560  filters=512
  561  activation=leaky
  562  [convolutional]
  563  batch_normalize=1
  564  filters=256
  565  size=1
  566  stride=1
  567  pad=1
  568  activation=leaky
  569  [convolutional]
  570  batch_normalize=1
  571  size=3
  572  stride=1
  573  pad=1
  574  filters=512
  575  activation=leaky
  576  [convolutional]
  577  size=1
  578  stride=1
  579  pad=1
  580  filters=255
  581  activation=linear
  582  [yolo]
  583  mask = 3,4,5
  584  anchors = 10,13,  16,30,  33,23,  30,61,  62,45,  59,119,  116,90,  156,198,  373,326
  585  classes=80
  586  num=9
  587  jitter=.3
  588  ignore_thresh = .7
  589  truth_thresh = 1
  590  random=1
  591  [route]
  592  layers = -4
  593  [convolutional]
  594  batch_normalize=1
  595  filters=128
  596  size=1
  597  stride=1
  598  pad=1
  599  activation=leaky
  600  [upsample]
  601  stride=2
  602  [route]
  603  layers = -1, 36
  604  [convolutional]
  605  batch_normalize=1
  606  filters=128
  607  size=1
  608  stride=1
  609  pad=1
  610  activation=leaky
  611  [convolutional]
  612  batch_normalize=1
  613  size=3
  614  stride=1
  615  pad=1
  616  filters=256
  617  activation=leaky
  618  [convolutional]
  619  batch_normalize=1
  620  filters=128
  621  size=1
  622  stride=1
  623  pad=1
  624  activation=leaky
  625  [convolutional]
  626  batch_normalize=1
  627  size=3
  628  stride=1
  629  pad=1
  630  filters=256
  631  activation=leaky
  632  [convolutional]
  633  batch_normalize=1
  634  filters=128
  635  size=1
  636  stride=1
  637  pad=1
  638  activation=leaky
  639  [convolutional]
  640  batch_normalize=1
  641  size=3
  642  stride=1
  643  pad=1
  644  filters=256
  645  activation=leaky
  646  [convolutional]
  647  size=1
  648  stride=1
  649  pad=1
  650  filters=255
  651  activation=linear
  652  [yolo]
  653  mask = 0,1,2
  654  anchors = 10,13,  16,30,  33,23,  30,61,  62,45,  59,119,  116,90,  156,198,  373,326
  655  classes=80
  656  num=9
  657  jitter=.3
  658  ignore_thresh = .7
  659  truth_thresh = 1
  660  ls
  661  cd cfg
  662  ls
  663  [net]
  664  # Testing
  665  # batch=1
  666  # subdivisions=1
  667  # Training
  668  batch=64
  669  subdivisions=16
  670  width=608
  671  height=608
  672  channels=3
  673  momentum=0.9
  674  decay=0.0005
  675  angle=0
  676  saturation = 1.5
  677  exposure = 1.5
  678  hue=.1
  679  learning_rate=0.001
  680  burn_in=1000
  681  max_batches = 500200
  682  policy=steps
  683  steps=400000,450000
  684  scales=.1,.1
  685  [convolutional]
  686  batch_normalize=1
  687  filters=32
  688  size=3
  689  stride=1
  690  pad=1
  691  activation=leaky
  692  # Downsample
  693  [convolutional]
  694  batch_normalize=1
  695  filters=64
  696  size=3
  697  stride=2
  698  pad=1
  699  activation=leaky
  700  [convolutional]
  701  batch_normalize=1
  702  filters=32
  703  size=1
  704  stride=1
  705  pad=1
  706  activation=leaky
  707  [convolutional]
  708  batch_normalize=1
  709  filters=64
  710  size=3
  711  stride=1
  712  pad=1
  713  activation=leaky
  714  [shortcut]
  715  from=-3
  716  activation=linear
  717  # Downsample
  718  [convolutional]
  719  batch_normalize=1
  720  filters=128
  721  size=3
  722  stride=2
  723  pad=1
  724  activation=leaky
  725  [convolutional]
  726  batch_normalize=1
  727  filters=64
  728  size=1
  729  stride=1
  730  pad=1
  731  activation=leaky
  732  [convolutional]
  733  batch_normalize=1
  734  filters=128
  735  size=3
  736  stride=1
  737  pad=1
  738  activation=leaky
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

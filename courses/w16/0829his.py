    1  ls
    2  lsusb
    3  df -h
    4  df 0h
    5  df -h
    6  sudo cp -ax / '/media/nvidia/JetsonSD32' && sync
    7  cd /boot/extlinux/
    8  ls
    9  sudo cp extlinux.conf /media/nvidia/JetsonSD32/nw/extlinux.conf.original
   10  sudo cp extlinux.conf extlinux.conf.original
   11  vi extlinux.conf
   12  nautilus .
   13  scp nvidia@192.168.101.4:/home/nvidia/ufftest.tar.gz /home/nvidia/Desktop/
   14  sudo scp nvidia@192.168.101.4:/home/nvidia/ufftest.tar.gz /home/nvidia/Desktop/
   15  scp nvidia@192.168.101.4:/home/nvidia/ufftest.tar.gz /home/nvidia/Desktop/
   16  ~/Desktop/
   17  cd ~/Desktop/
   18  cp ./ufftest.tar.gz /opt/nvidia/deepstream/deepstream-4.0/sources/objectDetector_SSD/
   19  cd /opt/nvidia/deepstream/deepstream-4.0/sources/objectDetector_SSD/
   20  ls
   21  export CUDA_VER=10.0
   22  make -C nvdsinfer_custom_impl_ssd
   23  deepstream-app -c deepstream_app_config_ssd.txt 
   24  ls
   25  tar -xvf ufftest.tar.gz 
   26  ls
   27  rm ufftest.tar.gz
   28  ls
   29  cd deepstream_uff/
   30  ls
   31  mv ./* ../
   32  ls
   33  cd ..
   34  ls
   35  make -C nvdsinfer_custom_impl_ssd
   36  deepstream-app -c deepstream_app_config_ssd.txt 
   37  sudo deepstream-app -c deepstream_app_config_ssd.txt 
   38  ls
   39  cp _sample_ssd_relu6.uff sample_ssd_relu6.uff 
   40  sudo deepstream-app -c deepstream_app_config_ssd.txt
   41  l
   42  ls
   43  cd ..
   44  ls
   45  cd objectDetector_
   46  cd objectDetector_Yolo/
   47  las
   48  ls
   49  cd ../objectDetector_SSD/
   50  ls
   51  mv sample_ssd_relu6.uff best.uff
   52  mv ~/Desktop/frozen_inference_graph.uff ./
   53  ls
   54  mv frozen_inference_graph.uff sample_ssd_relu6.uff 
   55  deepstream-app -c deepstream_app_config_ssd.txt 
   56  history
   57  ls
   58  cp sample_ssd_relu6.uff ~/Desktop/
   59  nvcc --version
   60  deepstream
   61  deepstream --version
   62  deepstream-app --verson
   63  deepstream-app --version
   64  cd /opt/nvidia/deepstream/deepstream-4.0/sources/objectDetector_Yolo/
   65  ls
   66  ./nvdsinfer_custom_impl_Yolo/
   67  ls /nvdsinfer_custom_impl_Yolo/
   68  ls /nvdsinfer_custom_impl_Yolo
   69  cd nvdsinfer_custom_impl_Yolo/
   70  ls
   71  cd ..
   72  ls
   73  ./prebuild.sh 
   74  make -C nvdsinfer_custom_impl_Yolo
   75  export CUDA_VER=10.0
   76  make -C nvdsinfer_custom_impl_Yolo
   77  deepstream-app -c deepstream_app_config_yoloV3_tiny.txt
   78  deepstream-app -c deepstream_app_config_yoloV3.txt 
   79  cd /opt/nvidia/deepstream/deepstream-4.0/sources/objectDetector_SSD/
   80  ls
   81  vi ssd_coco_labels.txt 
   82  ls
   83  cd ..
   84  cd
   85  ls
   86  cd /opt/nvidia/deepstream/deepstream-4.0/sources/objectDetector_SSD/
   87  ls
   88  cd .
   89  cd ..
   90  ls
   91  cd objectDetector_Yolo/
   92  ls
   93  vi README 
   94  df -h
   95  ls
   96  cd ~
   97  ls
   98  vi VisionWorks-SFM-0.90-Samples/
   99  ls
  100  cd /VisionWorks-SFM-0.90-Samples/
  101  vi /VisionWorks-SFM-0.90-Samples/
  102  vi /VisionWorks-SFM-0.90-Samples
  103  ./VisionWorks-SFM-0.90-Samples
  104  cd VisionWorks-SFM-0.90-Samples/
  105  ls
  106  make
  107  make all
  108  vi Makefile 
  109  cd samples/
  110  ls
  111  cd sfm/
  112  ls
  113  make
  114  make all
  115  cd ../..'
  116  cd ../../
  117  ls
  118  cd ../..s
  119  ls
  120  cd ../
  121  ls
  122  cd darknet/weights/
  123  wget https://pjreddie.com/files/yolov3-tiny.weights
  124  wget https://pjreddie.com/media/files/yolov3-tiny.weights
  125  ls
  126  git clone https://github.com/pjreddie/darknet
  127  cd darknet/
  128  make
  129  sudo apt update && sudo apt upgrade -y
  130  cd darknet/
  131  ls
  132  cd cfg/
  133  ls
  134  cd ./
  135  cd ..
  136  mkdir weights
  137  cd weights/
  138  ls
  139  wget https://pjreddie.com/media/files/yolov3.weihts
  140  wget https://pjreddie.com/media/files/yolov3.weights
  141  cd ~/
  142  ls
  143  mv darknet darknet-origin
  144  ls
  145  git clone https://github.com/JinFree/darknet
  146  cd darknet
  147  ls
  148  chmod +x build_for_tx2.sh
  149  ./build_for_tx2.sh 
  150  ls
  151  ll
  152  ./yolov3-tiny_usbcam.sh 
  153  vi yolov3-tiny_usbcam.sh 
  154  ./yolov3-tiny_usbcam.sh 
  155  jetson_clocks
  156  sudo jetson_clocks
  157  cd darknet/
  158  ls
  159  ./darknet detect cfg/yolov3-tiny.cfg weights/yolov3-tiny.weights -c 1
  160  ./darknet detect cfg/yolov3-tiny.cfg weights/yolov3-tiny.weights /dev/video1
  161  ./darknet detect cfg/yolov3-tiny.cfg weights/yolov3-tiny.weights -c 1
  162  ./darknet detecter demo cfg/yolov3-tiny.cfg weights/yolov3-tiny.weights -c 1
  163  ./darknet detector demo cfg/.cfg weights/yolov3-tiny.weights -c 1
  164  ./darknet detecter demo cfg/coco.data cfg/yolov3-tiny.cfg weights/yolov3-tiny.weights -c 1
  165  ./darknet detector demo cfg/coco.data cfg/yolov3-tiny.cfg weights/yolov3-tiny.weights -c 1
  166  ./darknet detector demo cfg/coco.data cfg/yolov3-tiny.cfg weights/yolov3-tiny.weights -c /dev/video1
  167  ./darknet detector demo cfg/coco.data cfg/yolov3-tiny.cfg weights/yolov3-tiny.weights -c 1
  168  ./darknet detector demo cfg/coco.data cfg/yolov3-tiny.cfg weights/yolov3-tiny.weights
  169  ./darknet detector demo cfg/coco.data cfg/yolov3.cfg weights/yolov3.weights -c 1
  170  cd /opt/nvidia/deepstream/deepstream-4.0/samples/streams/
  171  l
  172  ls
  173  cd ..
  174  ls
  175  cd ..
  176  cd sources/objectDetector_Yolo/
  177  ls
  178  vi README 
  179  deepstream-app -c dev/video1  deepstream_app_config_yoloV3_tiny.txt
  180  deepstream-app -c 1 deepstream_app_config_yoloV3_tiny.txt
  181  vi deepstream-app
  182  ls
  183  cd nvdsinfer_custom_impl_Yolo/
  184  ls
  185  vi Makefile 
  186  vi nvdsparsebbox_Yolo.cpp 
  187  ;s
  188  ls
  189  vi yolo.h 
  190  deepstream-app -c 1 deepstream_app_config_yoloV3_tiny.txt
  191  sh 
  192  history
  193  deepstream-app qls deepstream_app_config_yoloV3_tiny.txt
  194  d ../../objectDetector_SSD/
  195  ls
  196  deepstream-app -c deepstream_app_config_yoloV3_tiny.txt
  197  cd ../../objectDetector_SSD/
  198  ls
  199  deepstream-app -c deepstream_app_config_ssd.txt 
  200  ls
  201  vi README 
  202  cd darknet
  203  ls
  204  ./yolov3-tiny_usbcam.sh 
  205  shutdown -h now
  206  ls
  207  cd /opt/nvidia/deepstream/deepstream-4.0/sources/
  208  ls
  209  cd objectDetector_SSD/
  210  ls
  211  vi README 
  212  sudo deepstream-app -c deepstream_app_config_ssd.txt
  213  ls
  214  vi deepstre_no
  215  vi deepstrem_note.txt 
  216  sudo deepstream-app -c deepstream_app_config_ssd.txt Tegra /dev/video1
  217  sudo deepstream-app deepstream_app_config_ssd.txt /dev/video1
  218  ls
  219  cd deepstream_uff/
  220  ls
  221  cd ..
  222  deepstream-app help
  223  deepstream-app -c
  224  ls
  225  cd ..
  226  ls
  227  cd apps/
  228  ls
  229  cd sample_apps/deepstream-
  230  cd sample_apps/
  231  sl
  232  ls
  233  cd deepstream-app/
  234  ls
  235  cd deep_app_cofig_parser.c
  236  vi deep_app_cofig_parser.c
  237  vi deepstream_app.c
  238  ls
  239  vi README 
  240  vi deepstream_app_config_parser.c 
  241  ls
  242  vi deepstream_app.h
  243  fine name 
  244  find help
  245  find
  246  find video
  247  find -name video
  248  find -name video ./
  249  find --name video ./
  250  find ./ |grep video
  251  find --help
  252  find -name *
  253  find -name s/name
  254  ls
  255  cat ./* |grep capture
  256  cat ./*
  257  cat ./* | cap
  258  cat ./* | grep cap
  259  cat ./* | grep video
  260  ls
  261  cd ..
  262  ls
  263  cd ../..
  264  ls
  265  cd objectDetector_SSD/
  266  ls
  267  vi config_infer_primary_ssd.txt 
  268  vi deepstream_app_config_ssd.txt 
  269  sudo deepstream-app -c deepstream_app_config_ssd.txt
  270  vi deepstream_app_config_ssd.txt 
  271  sudo deepstream-app -c deepstream_app_config_ssd.txt vtl2-ctl -d 1 -all
  272  vtl2-ctl -d 1 -all
  273  sudo deepstream-app -c deepstream_app_config_ssd.txt
  274  sudo deepstream-app -c deepstream_app_config_ssd.txt vtl2-ctl /dev/video1 -all
  275  sudo deepstream-app -c deepstream_app_config_ssd.txt vtl2-ctl /dev/video1
  276  vi deepstream_app_config_ssd.txt 
  277  sudo deepstream-app -c deepstream_app_config_ssd.txt vtl2-ctl /dev/video1
  278  sudo deepstream-app -c deepstream_app_config_ssd.txt
  279  vi deepstream_app_config_ssd.txt 
  280  sudo deepstream-app -c deepstream_app_config_ssd.txt
  281  history
  282  cd darknet
  283  ls
  284  cd ..
  285  cd /opt/nvidia/deepstream/deepstream-4.0/sources/objectDetector_SSD/
  286  ls
  287  vi README 
  288  cd ../../..
  289  ls
  290  cd deepstream-4.0/
  291  ls
  292  cd ..
  293  ls
  294  cd /media/nvidia/NWISM_128G/
  295  ls
  296  mkdir ob_SSD
  297  ls
  298  cd ob_SSD/
  299  ls
  300  ./yolov3-tiny_usbcam.sh 
  301  history
  302  ls
  303  cd darknet/
  304  ls
  305  jetson_clocks 
  306  sudo jetson_clocks 
  307  ./yolov3-tiny_usbcam.sh 
  308  cp /opt/nvidia/deepstream/deepstream-4.0/sources/objectDetector_SSD/
  309  ls
  310  cp /opt/nvidia/deepstream/deepstream-4.0/sources/objectDetector_SSD/* ./ob_SSD/
  311  sudo cp -r /opt/nvidia/deepstream/deepstream-4.0/sources/objectDetector_SSD/* ./ob_SSD/
  312  ls
  313  vi NVIDIA/
  314  head -n 1 /etc/nv_tegra_release
  315  python --version
  316  python3 --version
  317  cat /etc/nv_tegra_release
  318  python3 --version
  319  ls
  320  git clone https://github.com/jetsonhacks/installROSXavier.git
  321  cd installROSXavier/
  322  ls
  323  ./installROS.sh -p ros-melodic-desktop -p ros-melodic-rgbd-launch
  324  sudo ./installROS.sh -p ros-melodic-desktop -p ros-melodic-rgbd-launch && ./setupCatkinWorkspace.sh
  325  vi ~/.bashrc
  326  sudo roscore
  327  roscore
  328  roscore
  329  source ~/.bashrc
  330  source ~/catkin_ws/devel/setup.bash
  331  roscore
  332  sudo roscore
  333  roscore
  334  cd catkin_ws/
  335  ls
  336  cd src/
  337  ls
  338  cd ..
  339  catkin_make
  340  vi ~/.bashrc
  341  sudo ./installROS.sh -p ros-melodic-desktop -p ros-melodic-rgbd-launch
  342  vi ~/.bashrc
  343  source ~/catkin_ws/devel/setup.bash
  344  source ~/.bashrc
  345  roscore
  346  sudo roscore
  347  sudo -s
  348  turtle $ rosrun turtlesim turtlesim_node
  349  rosrun turtlesim turtlesim_node
  350  ifconfig
  351  rosrun turtlesim turtle_teleop_key
  352  vi ~/.bashrc 
  353  history
  354  history | grep source
  355  source ~/.bashrc
  356  source ~/catkin_ws/devel/setup.bash
  357  sudo apt install ./sdkmanager_0.9.14-4954_amd64.deb 
  358  sdkmanager
  359  rosrun turtlesim turtle_teleop_key
  360  vi ~/.bashrc 
  361  cat /usr/include/cudnn.h | grep CUDNN_MAJOR
  362  cd /opt/nvidia/deepstream/deepstream-4.0/sources/objectDetector_
  363  cd /opt/nvidia/deepstream/deepstream-4.0/sources/objectDetector_SSD/
  364  ls
  365  history
  366  sudo deepstream-app -c deepstream_app_config_ssd.txt
  367  rosrun turtlesim turtle_teleop_key
  368  cd ~/
  369  rosrun turtlesim turtle_teleop_key
  370  roscore
  371  sudo -s
  372  vi ~/.bashrc 
  373  cd catkin_ws/
  374  cd src/
  375  ls
  376  sudo git clone https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git && git clone https://github.com/ROBOTIS-GIT/turtlebot3.git
  377  cd ~/catkin_ws && catkin_make
  378  sudo catkin_make
  379  catkin_make
  380  cd src/
  381  ls
  382  vi CMakeLists.txt 
  383  git clone https://github.com/ROBOTIS-GIT/turtlebot3_msgs
  384  cd ..
  385  catkin_make
  386  git clone  https://github.com/ros-simulation/gazebo_ros_pkgs.git
  387  ls
  388  mv gazebo_ros_pkgs cd ./src
  389  mv gazebo_ros_pkgs ./src
  390  mv gazebo_ros_pkgs /src
  391  mv ./gazebo_ros_pkgs /src
  392  ls
  393  catkin_make
  394  curl -sSL http://get.gazebosim.org | sh
  395  gazebo
  396  sudo apt-get install gazebo9
  397  catkin_make
  398  ls
  399  source ./devel/setup.bash
  400  source ~/.bashrc 
  401  ifconfig
  402  . ./devel/setup.bash
  403  . catkin_ws/src/devel/setup.bash
  404  . catkin_ws/devel/setup.bash
  405  catkin_make
  406  cd catkin_ws/
  407  cd src/
  408  catkin_make
  409  cd ..
  410  catkin_make
  411  ls
  412  vi ME
  413  vi README.md 
  414  sudo apt-get update
  415  sudo sh -c 'echo "deb http://packages.osrfoundation.org/gazebo/ubuntu-stable `lsb_release -cs` main" > /etc/apt/sources.list.d/gazebo-stable.list'
  416  gazebo
  417  ifconfig
  418  $ gazebo --version
  419  sudo apt install libgazebo7-dev
  420  sudo apt install libgazebo9-dev
  421  ls
  422  rm -rf build
  423  rm -rf devel
  424  catkin_make
  425  sudo apt-get install libpolled-camera-dev
  426  catkin_make
  427  sudo apt-get install libpolled-camera-dev
  428  ls
  429  rm -rf build
  430  rm -rf devel/
  431  ls
  432  catkin_make
  433  cd src/
  434  ls
  435  git clone https://github.com/ros-perception/image_common.git
  436  git branch hydro-devel
  437  ls
  438  cd image_common/
  439  ls
  440  git branch hydro-devel
  441  git branch
  442  cd ..
  443  ls
  444  rm -rf build
  445  rm -rf devel
  446  ls
  447  catkin_make
  448  ls
  449  cd src/
  450  git clone https://github.com/ros-controls/control_toolbox.git
  451  ls
  452  cd ..
  453  ls
  454  rm -rf build devel
  455  ls
  456  catkin_make
  457  cd src/
  458  git clone https://github.com/ros-controls/realtime_tools.git
  459  cd ..
  460  catkin_make
  461  git clone https://github.com/ros-controls/ros_control.git
  462  ls
  463  mv ros_control ./src/
  464  ls
  465  cd src/
  466  ls
  467  cd ..
  468  catkin_make
  469  ls
  470  source devel/setup.bash
  471  source ~/.bashrc 
  472  gazebo
  473  export TURTLEBOT3_MODEL=burger]
  474  export TURTLEBOT3_MODEL=burger
  475  roslaunch turtlebot3_fake turtlebot3_fake.launch
  476  cd src/
  477  ls
  478  roslaunch turtlebot3_fake turtlebot3_fake.launch
  479  export TURTLEBOT3_MODEL=burger
  480  roslaunch turtlebot3_fake turtlebot3_fake.launch
  481  ls
  482  cd turtlebot3
  483  ls
  484  cd ../
  485  ls
  486  cd turtlebot3_simulations/
  487  ls
  488  sudo apt-get install ros-melodic-gazebo-ros
  489  roslaunch turtlebot3_fake turtlebot3_fake.launch
  490  history
  491  source devel/setup.bash
  492  git branch
  493  source ~/.bashrc 
  494  cd ..
  495  source devel/setup.bash
  496  roslaunch turtlebot3_fake turtlebot3_fake.launch
  497  sudo apt-get install ros-melodic-gazebo-dev
  498  sudo apt-get install ros-melodic-gazebo-msgs
  499  source ./devel/setup.bash
  500  roslaunch turtlebot3_fake turtlebot3_fake.launch
  501  vi ~/.bashrc 
  502  ifconfig
  503  vi tttt.sh 
  504  ls
  505  cd catkin_ws/
  506  ls
  507  cd ..
  508  rm tttt.sh 
  509  cd catkin_ws/
  510  ls
  511  mv tttt.sh ~/
  512  kls
  513  ls
  514  vi tttt.sh 
  515  vi mysetup.sh 
  516  cd catkin_ws/src/turtlebot3
  517  cd ../..
  518  export TURTLEBOT3_MODEL=burger
  519  roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
  520  sudo -s
  521  roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
  522  export TURTLEBOT3_MODEL=burger
  523  roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
  524  sudo apt-get install ros-melodic-ar-track-alvar-msgs
  525  cd catkin_ws/
  526  sudo apt autoremove
  527  export TURTLEBOT3_MODEL=burger
  528  roslaunch turtlebot3_fake turtlebot3_fake.launch
  529  cd ..
  530  vi tttt.sh
  531  chmod 777 tttt.sh 
  532  sudo ./tttt.sh 
  533  cd ls
  534  lsl
  535  ls
  536  mkdir catkin_ws
  537  mv turtlebot* ./catkin_ws/
  538  sudo mv turtlebot* ./catkin_ws/
  539  ls
  540  mv tttt.sh ./catkin_ws/
  541  cd catkin_ws/
  542  ls
  543  cd ..
  544  vi setupCatkinWorkspace.sh
  545  chmod 777 setupCatkinWorkspace.sh 
  546  ./setupCatkinWorkspace.sh 
  547  ls
  548  mv tttt.sh mysetup.sh
  549  ls
  550  ./mysetup.sh
  551  ./mysetup.sh -y
  552  sudo ./mysetup.sh -y
  553  time sudo ./mysetup.sh -y
  554  vi mysetup.sh 
  555  time sudo ./mysetup.sh -y
  556  cd ~/catkin_ws/
  557  catkin_make
  558  sudo catkin_make
  559  catkin_make
  560  ls
  561  cd src/
  562  ls
  563  cd ..
  564  catkin_make
  565  sudo catkin_make
  566  sudo -s
  567  ls
  568  sudo catkin_make
  569  catkin_make
  570  . ./devel/setup.bash
  571  sudo apt-get install ros-melodic-gazebo-ros
  572  sudo apt-get install ros-melodic-gazebo-dev
  573  sudo apt-get install ros-melodic-gazebo-msgs
  574  catkin_make
  575  source ./devel/setup.bash
  576  export TURTLEBOT3_MODEL=burger
  577  roslaunch turtlebot3_fake turtlebot3_fake.launch
  578  rostopic list
  579  ls
  580  vi Vi
  581  vi VisionWorks-SFM-0.90-Samples/
  582  ls
  583  cd Vi
  584  cd VisionWorks-SFM-0.90-Samples/
  585  ls
  586  vi Makefile 
  587  cd samples/
  588  ls
  589  cd sfm/
  590  ls
  591  cd .
  592  cd ..
  593  ls
  594  cd ..
  595  ls
  596  cd bin/
  597  ls
  598  cd aarch64/linux/release/
  599  ls
  600  vi nvx_sample_sfm 
  601  ls
  602  ./nvx_sample_sfm 
  603  roslaunch turtlebot3_fake turtlebot3_fake.launch
  604  export TURTLEBOT3_MODEL=burger
  605  roslaunch turtlebot3_fake turtlebot3_fake.launch
  606  roscore 
  607  sudo chmod 777 -R /home/nvidia/.ros/
  608  roscore 
  609  export TURTLEBOT3_MODEL=burger
  610  roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
  611  vi ~/.bashrc 
  612  . ~/.bashrc 
  613  rostopic list
  614  roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
  615  roslaunch turtlebot3_gazebo turtlebot3_empty_world.launch
  616  roslaunch turtlebot3_gazebo turtlebot3_world.launch
  617  ls
  618  cd /opt/nvidia/
  619  ls
  620  cd deepstream/
  621  ls
  622  cd ..
  623  cd deepstream/deepstream-4.0/
  624  ls
  625  find -name "jetson_clock"
  626  sudo find -name "jetson_clock"
  627  sudo find -name "jetson_clock.sh"
  628  sudo find -name "jetson_clocks.sh"
  629  sudo find -name "jetson_clock*.*"
  630  cd /
  631  sudo find -name "jetson_clock*.*"
  632  roslaunch turtlebot3_gazebo turtlebot3_house.launch
  633  ls
  634  vi ~/.ignition/fuel/config.yaml 
  635  roslaunch turtlebot3_gazebo turtlebot3_house.launch
  636  roslaunch turtlebot3_gazebo turtlebot3_world.launch
  637  roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
  638  roslaunch turtlebot3_gazebo turtlebot3_simulation.launch
  639  roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=$HOME/map.yaml
  640  roslaunch turtlebot3_gazebo turtlebot3_gazebo_rviz.launch
  641  roslaunch turtlebot3_gazebo turtlebot3_world.launch
  642  roslaunch turtlebot3_slam turtlebot3_slam.launch slam_methods:=gmapping
  643  roslaunch turtlebot3_gazebo turtlebot3_world.launch
  644  sudo /usr/bin/jetson_clocks 
  645  roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
  646  rqt_graph 
  647  rqt_graph
  648  ls
  649  ll
  650  ll m*
  651  roscore
  652  vi ~/.bashrc 
  653  $ roslaunch turtlebot3_gazebo turtlebot3_world.launch
  654  roslaunch turtlebot3_gazebo turtlebot3_world.launch
  655  roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
  656  rostopic list
  657  roslaunch turtlebot3_bringup turtlebot3_robot.launch
  658  export TURTLEBOT3_MODEL=${TB3_MODEL}
  659  . ~/.bashrc 
  660  vi ~/.bashrc 
  661  . ~/.bashrc 
  662  source ~/.bashrc 
  663  roslaunch turtlebot3_gazebo turtlebot3_simulation.launch
  664  roslaunch turtlebot3_gazebo turtlebot3_house.launch
  665  roslaunch turtlebot3_slam turtlebot3_slam.launch slam_methods:=gmapping
  666  vi ~/.bashrc 
  667  rostopic list
  668  rostopic list
  669  rostopic echo /cmd_vel 
  670  rosrun map_server map_saver -f ~/map
  671  ls
  672  rosrun map_server map_saver -f ~/map1
  673  vi map.yaml 
  674  /usr/bin/jetson_clocks 
  675  sudo /usr/bin/jetson_clocks 
  676  roslaunch turtlebot3_gazebo turtlebot3_simulation.launch
  677  rostopic list
  678  vi map.pgm 
  679  xdg-open map.pgm 
  680  rqt_graph 
  681  roslaunch turtlebot3_gazebo turtlebot3_world.launch
  682  roslaunch turtlebot3_slam turtlebot3_slam.launch slam_methods:=gmapping
  683  roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=$HOME/map.yaml
  684  roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=$HOME/map2.yaml
  685  roslaunch turtlebot3_gazebo turtlebot3_simulation.launch
  686  roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
  687  roslaunch turtlebot3_gazebo turtlebot3_simulation.launch
  688  roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
  689  roslaunch turtlebot3_gazebo turtlebot3_simulation.launch
  690  roslaunch turtlebot3_gazebo turtlebot3_autorace.launch 
  691  roslaunch turtlebot3_gazebo turtlebot3_stage_4.launch 
  692  roslaunch turtlebot3_gazebo multi_turtlebot3_slam.launch 
  693  roslaunch turtlebot3_gazebo multi_turtlebot3.launch 
  694  roslaunch turtlebot3_gazebo turtlebot3_world.launch
  695  roslaunch turtlebot3_gazebo turtlebot3_stage_4.launch 
  696  roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=$HOME/map.yaml
  697  cd catkin_ws/
  698  roslaunch turtlebot3_gazebo turtlebot3_simulation.launch
  699  sudo cp -r catkin_ws /media/nvidia/USB_LINUX/0829/
  700  ls
  701  ll
  702  df -h
  703  ls
  704  ll
  705  sudo cp map.pgm /media/nvidia/USB_LINUX/
  706  cd catkin_ws/src/
  707  ;s
  708  ls
  709  find -name "multi*"
  710  vi /turtlebot3_simulations/turtlebot3_gazebo/launch/multi_turtlebot3_slam.launch
  711  vi ./turtlebot3_simulations/turtlebot3_gazebo/launch/multi_turtlebot3_slam.launch
  712  history 
  713  rqt_graph 
  714  history 
  715  roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
  716  ROS_NAMESPACE=tb3_1 roslaunch turtlebot3_slam turtlebot3_gmapping.launch set_base_frame:=tb3_1/base_footprint set_odom_frame:=tb3_1/odom set_map_frame:=tb3_1/map
  717  $ roslaunch turtlebot3_gazebo multi_map_merge.launch
  718  roslaunch turtlebot3_gazebo multi_map_merge.launch
  719  sudo apt-get install ros-melodic-multirobot-map-merge
  720  cd catkin_ws/src/
  721  ls
  722  git clone https://github.com/hrnr/m-explore.git 
  723  sudo git clone https://github.com/hrnr/m-explore.git 
  724  cd ..
  725  cm
  726  catkin_make
  727  sudo catkin_make
  728  catkin_make
  729  sudo -s
  730  catkin_make
  731  history
  732  roslaunch turtlebot3_gazebo multi_turtlebot3.launch 
  733  sudo apt-get install ros-kinetic-multirobot-map-merge
  734  roslaunch turtlebot3_gazebo multi_map_merge.launch
  735  history
  736  roslaunch turtlebot3_gazebo multi_turtlebot3_slam.launch 
  737  history
  738  ROS_NAMESPACE=tb3_0 roslaunch turtlebot3_slam turtlebot3_gmapping.launch set_base_frame:=tb3_0/base_footprint set_odom_frame:=tb3_0/odom set_map_frame:=tb3_0/map
  739  ROS_NAMESPACE=tb3_2 roslaunch turtlebot3_slam turtlebot3_gmapping.launch set_base_frame:=tb3_2/base_footprint set_odom_frame:=tb3_2/odom set_map_frame:=tb3_2/map
  740  ROS_NAMESPACE=tb3_0 roslaunch turtlebot3_gazebo turtlebot3_simulation.launch 
  741  sudo /usr/bin/jetson_clocks 
  742  rostopic list
  743  ROS_NAMESPACE=tb3_1 rosrun turtlebot3_teleop turtlebot3_simulation.launch
  744  ROS_NAMESPACE=tb3_1 rosrun turtlebot3_gazebo turtlebot3_simulation.launch
  745  ROS_NAMESPACE=tb3_1 roslaunch turtlebot3_gazebo turtlebot3_simulation.launch
  746  roslaunch turtlebot3_gazebo multi_turtlebot3.launch 
  747  sudo /usr/bin/jetson_clocks 
  748  ROS_NAMESPACE=tb3_0 roslaunch turtlebot3_slam turtlebot3_gmapping.launch set_base_frame:=tb3_0/base_footprint set_odom_frame:=tb3_0/odom set_map_frame:=tb3_0/map
  749  ROS_NAMESPACE=tb3_1 roslaunch turtlebot3_slam turtlebot3_gmapping.launch set_base_frame:=tb3_1/base_footprint set_odom_frame:=tb3_1/odom set_map_frame:=tb3_1/map
  750  ROS_NAMESPACE=tb3_2 roslaunch turtlebot3_slam turtlebot3_gmapping.launch set_base_frame:=tb3_2/base_footprint set_odom_frame:=tb3_2/odom set_map_frame:=tb3_2/map
  751  rosrun rviz rviz -d `rospack find turtlebot3_gazebo`/rviz/multi_turtlebot3_slam.rviz
  752  roslaunch turtlebot3_gazebo multi_map_merge.launch
  753  history
  754  history >> ~/Desktop/0829his.py

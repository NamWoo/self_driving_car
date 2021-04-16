#!/bin/sh
# 2_end.sh

# echo 'ps | grep "sk_app" | awk "{if($3!~/grep/)print $1}"'
rmmod sk
rm /dev/sk

# check()
# {
#     if [ ps | grep "sk_app" | awk '{if($3!~/grep/)print $1}'];
#         then
#         echo "exists. yo"
#         return 0
#    else
#         echo "No such file."
#         return 1
#     fi
# }

# kill -9 "$check"



# aaa = ps | grep "sk_app" | awk '{if($3!~/grep/)print $1}'




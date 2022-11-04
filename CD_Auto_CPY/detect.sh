#!/bin/bash

dest_path="/opt/.haha"

while true 
do
    cdrom=`blkid | grep udf`
    #cdrom=`blkid | grep xfs`
    if [ "$?" -eq 0 ]
        then
        dev_path=`echo $cdrom | awk '{print $1}' | sed 's/\:$//g'`
        path=`mount | grep $dev_path`
        if test -z "$path"; 
            then
            sleep 2
        else
            echo "found! $path"
            path1=${path% *}
            path2=${path1% *}
            path3=${path2% *}
            path4=${path3#* }
            mount_path=${path4#* }
            echo $dev_path 
            echo $mount_path 
            bingo=`stat $dest_path &>/dev/null`
            if [ "$?" -ne 0 ]
                then
                mkdir -p $dest_path
                cp -r "$mount_path" $dest_path
                sleep 20
                break
                #echo "cp -rf "$mount_path" $dest_path"
            else
                echo "Bingo!!!!"
            fi
        fi
    fi
    sleep 2
done

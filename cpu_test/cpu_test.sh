python -c "from multiprocessing import cpu_count;from os import system; system(str('yes > /dev/null & '*            cpu_count())[:-2])" > /dev/null 2>&1 &
 
echo "Starting to stress the cpu..."
echo
echo "Press ENTER/RETURN to stop."
read
killall yes > /dev/null 2>&1
echo "Finished $(basename $0)"

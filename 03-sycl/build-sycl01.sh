echo "start build run sycl01"

echo "01. build"
source /opt/intel/oneapi/setvars.sh
icpx -fsycl ./sycl01-device.cc 

echo "02. run"
./a.out

echo "end./"

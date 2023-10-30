#include <CL/sycl.hpp>
#include <iostream>
 
int main() {
 
    sycl::queue Q;
    std::cout << "Running on: " << Q.get_device().get_info<sycl::info::device::name>() << std::endl;
 
    int sum;
    std::vector<int> data{1, 1, 1, 1, 1, 1, 1, 1};
 
    sycl::buffer<int> sum_buf(&sum, 1);
    sycl::buffer<int> data_buf(data);
 
    Q.submit([&](sycl::handler& h)
    {
        sycl::accessor buf_acc{data_buf, h, sycl::read_only};
 
        h.parallel_for(sycl::range<1>{8},
                       sycl::reduction(sum_buf, h, std::plus<>()),
                       [=](sycl::id<1> idx, auto& sum)
        {
            sum += buf_acc[idx];
        });
    });
        
    sycl::host_accessor result{sum_buf, sycl::read_only};
    std::cout << "Sum equals " << result[0] << std::endl;
 
    return 0;
}

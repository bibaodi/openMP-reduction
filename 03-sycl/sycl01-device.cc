// Standard SYCL header
#include <CL/sycl.hpp>
int main() {
  sycl::device d;
// Exception checking for GPU availability
  try {
    d = sycl::device(sycl::gpu_selector());
  } catch (sycl::exception const &e) {
    std::cout << "Cannot select a GPU\n" << e.what() << "\n";
    std::cout << "Using a CPU device\n";
    d = sycl::device(sycl::cpu_selector());
  }

  std::cout << "Using " << d.get_info<sycl::info::device::name>()<<"\n";

	return 0;
}

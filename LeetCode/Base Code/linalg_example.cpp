#include "../linalg.h"
#include "../prettyprint.h"
#include <vector>
#include <iostream>

// float3, vec3, vec3f, point3f, simd_float3
using namespace linalg::aliases;
using namespace linalg::ostream_overloads;

int main() {
    linalg::mat<int, 3, 3> m = linalg::identity;
    int3x3 m2 = {{1,2,3},{4,5,6},{7,8,9}};

    std::vector<std::vector<int>> arr{{1,2,3},{4,5,6}};
    std::cout << m << std::endl;
    std::cout << m2 << std::endl;
    std::cout << arr << std::endl;
    return 0;
}

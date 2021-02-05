#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <tuple>
#include "prettyprint.h"

int main()
{
    std::vector<int> foo_vec{1,2,3};
    std::cout << foo_vec << std::endl;

    std::map<int, std::set<std::string>> foo_map = { 
                { 1, std::set<std::string>{ std::string("cat"),  std::string("dog"),  std::string("doe") } },
                { 3, std::set<std::string>{ std::string("goose"), std::string("moose"), std::string("ruse") } }
    };
    std::cout << foo_map << std::endl;

    std::vector<std::vector<int>> arr2d = {{1,2,3},{4,5,6},{7,8,9}};
    std::cout << arr2d << std::endl;


    int arr[] = { 1, 4, 9, 16 };
    std::cout << arr << std::endl;

    std::unordered_map<std::string, int> umap;
    umap["GeeksforGeeks"] = 10; 
    umap["Practice"] = 20; 
    umap["Contribute"] = 30;
    for (unsigned int i = 0; i != umap.bucket_count(); ++i) {
        std::cout << "Bucket " << i << ": " << bucket_print(umap, i) << std::endl;
    }

    std::tuple <int,char,float> tup1(20,'g',17.5); 
    std::cout << tup1 << std::endl;
}
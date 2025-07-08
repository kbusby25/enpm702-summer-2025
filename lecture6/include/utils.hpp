#include <memory>

void legacy_function(int *ptr);
void display(std::unique_ptr<int> v);
void reseat(std::unique_ptr<int> &v);
std::unique_ptr<int> create_resource();
void sink_shared_ptr(std::shared_ptr<int> ptr);
void reseat_shared_ptr(std::shared_ptr<int> &ptr);
std::shared_ptr<int> create_shared_resource();
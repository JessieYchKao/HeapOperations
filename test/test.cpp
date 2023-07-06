#include <gtest/gtest.h>
#include "heap.h"

// insert test
TEST(HeapTest, InsertTest) {
  Heap<int> heap;
  
  heap.insert(5);
  heap.insert(3);
  heap.insert(10);
  
  ASSERT_EQ(heap.size(), 3);
}

// remove test
TEST(HeapTest, RemoveTest) {
  Heap<int> heap;
  
  heap.insert(5);
  heap.insert(3);
  heap.insert(10);
  
  heap.remove();
  
  ASSERT_EQ(heap.size(), 2);
}

// Max heap test
TEST(HeapTest, MaxHeapTest) {
  Heap<int> heap;

  heap.insert(26);
  heap.insert(5);
  heap.insert(77);
  heap.insert(1);
  heap.insert(61);
  heap.insert(11);
  heap.insert(59);
  heap.insert(9);
  heap.insert(48);
  heap.insert(19);
  
  testing::internal::CaptureStdout();
  heap.print_heap();
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "77\t\n61\t59\t\n48\t19\t11\t26\t\n1\t9\t5\t\n");
  
  heap.remove(); // remove 77
  heap.remove(); // remove 61
  heap.insert(60);
  testing::internal::CaptureStdout();
  heap.print_heap();
  std::string output_after_remove = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output_after_remove, "60\t\n59\t26\t\n48\t19\t11\t5\t\n1\t9\t\n");
}

// Min heap test
TEST(HeapTest, MinHeapTest) {
  Heap<double> heap(false);

  heap.insert(12.8);
  heap.insert(35.1);
  heap.insert(44.4);
  heap.insert(0.05);
  heap.insert(17.82);
  heap.insert(29.4);
  heap.insert(10.22);
  heap.insert(8.888);
  heap.insert(0.146);
  heap.insert(19.3);
  
  testing::internal::CaptureStdout();
  heap.print_heap();
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "0.05\t\n0.146\t10.22\t\n8.888\t17.82\t44.4\t29.4\t\n35.1\t12.8\t19.3\t\n");
  
  heap.remove(); // remove 0.05
  heap.remove(); // remove 0.146
  heap.insert(15.6);
  testing::internal::CaptureStdout();
  heap.print_heap();
  std::string output_after_remove = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output_after_remove, "8.888\t\n12.8\t10.22\t\n15.6\t17.82\t44.4\t29.4\t\n35.1\t19.3\t\n");
}


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
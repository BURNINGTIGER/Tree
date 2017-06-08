#include <matrix.hpp>
#include <catch.hpp>
#include <iostream>

SCENARIO ("init", "[init]")
{
  BinaryTree<int> tree;
  REQUIRE(tree.root_() == nullptr);
}

SCENARIO ("output", "[output]")
{
  BinaryTree<int> tree;
  tree.insertNode(1);
  REQUIRE( std::cout << tree );
}

SCENARIO("findNode", "[findNode]")
  {
    BinaryTree<int> tree;
    tree.insert_node(4);
    tree.insert_node(2);
    REQUIRE(tree.find_node(2, tree.root_()) != nullptr);
    REQUIRE(tree.find_node(2, tree.root_())->data == 2);
  }

SCENARIO("insert", "[insert]")
{
  BinaryTree<int> tree;
  tree.insert_node(3);
  REQUIRE(tree.find_node(3, tree.root_())->data == 3);
}

SCENARIO("removeElement", "[remEl]")
{
  BinaryTree<int> obj;
  tree.insert_node(1);
  tree.insert_node(2);
  tree.insert_node(3);
  tree.deleteVal(1);
  REQUIRE(tree.find_node(1, tree.root_())== nullptr);
  REQUIRE(tree.find_node(2, tree.root_())== tree.root_());
  REQUIRE(tree.root_() != nullptr);
}

SCENARIO("DEL", "[Del]")
{
  BinaryTree<int> tree;
  tree.insert_node(1);
  tree.insert_node(2);
  tree.deleteVal(2);
  REQUIRE(obj.getCount() == 1);
}




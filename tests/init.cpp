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

SCENARIO("find", "[find]")
  {
    BinaryTree<int> tree;
    tree.insertNode(2);
    tree.insertNode(3);
    REQUIRE(tree.findNode(3, tree.root_()) != nullptr);
    REQUIRE(tree.findNode(3, tree.root_())->data == 3);
  }

SCENARIO("insert", "[insert]")
{
  BinaryTree<int> tree;
  tree.insertNode(4);
  REQUIRE(tree.findNode(4, tree.root_())->data == 4);
}

SCENARIO("remove", "[remove]")
{
  BinaryTree<int> tree;
  tree.insertNode(1);
  tree.insertNode(2);
  tree.insertNode(3);
  tree.deleteVal(1);
  REQUIRE(tree.findNode(1, tree.root_())== nullptr);
  REQUIRE(tree.findNode(2, tree.root_())== tree.root_());
  REQUIRE(tree.root_() != nullptr);
}

SCENARIO("delete", "[delete]")
{
  BinaryTree<int> tree;
  tree.insertNode(1);
  tree.insertNode(2);
  tree.deleteValue(2);
  REQUIRE(tree.getCount() == 1);
}




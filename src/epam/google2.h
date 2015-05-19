/*
 * google2.h
 *
 *  Created on: 03 февр. 2015 г.
 *      Author: andy
 */

#ifndef GOOGLE2_H_
#define GOOGLE2_H_

//Given a binary tree, print the nodes out grouping by level
//
// a
///  \
//b  d
//\
//c
//
//a
//bd
//c

#include <iostream>
#include <queue>

namespace google2 {

struct TreeNode {
  TreeNode(int i)
      : data(i),
        left(0),
        right(0) {
  }
  int data;
  TreeNode * left;
  TreeNode * right;
};

void swapQueWithSrc(std::queue<TreeNode*>& dest, std::queue<TreeNode*>& src) {
   while(!src.empty()) {
       TreeNode* treeNode = src.front();
        dest.push(treeNode);
        src.pop();
   }
}

void printLevelOrder(TreeNode* root) {
   if (!root) {
     return;
   }
   std::queue<TreeNode*> currentLevel, nextLevel;
   currentLevel.push(root);
   while(!currentLevel.empty()) {
       TreeNode* currentNode = currentLevel.front();
       currentLevel.pop();
       if (currentNode) {
         std::cout << currentNode->data << " ";
         nextLevel.push(currentNode->left);
         nextLevel.push(currentNode->right);
       }
       if (currentLevel.empty()) {
          std::cout << std::endl;
          swapQueWithSrc(currentLevel, nextLevel);
       }
   }
}

}

#endif /* GOOGLE2_H_ */

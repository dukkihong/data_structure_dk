#include <stdlib.h>
#include "traversalBT.h"

treeNode* makeRootNode(int size, treeNode* leftNode, treeNode* rightNode) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->size=size;
	root->right = rightNode;
	root->left = leftNode;
	return root;
}

int postorder_FolderSize(treeNode* root) {
	if (root) {
		postorder_FolderSize(root->left);
		postorder_FolderSize(root->right);
		FolderSize += root->size;
	}
	return FolderSize;
}
#include "avl_tree.h"

AvlTree_t* avltree_create(AvlCmpFn_t cmp_fn, AvlIterFn_t iter_fn)
{
	AvlTree_t *tree = NULL;

	if ((tree = malloc(sizeof(AvlTree_t))) == NULL)
	{
		printf("%s, %d: malloc failed.\n", __FUNCTION__, __LINE__);
		return NULL;
	}

	tree->root = NULL;
	tree->cmp_fn = cmp_fn;
	tree->iter_fn = iter_fn;

	return tree;
}

AvlNode_t* avlnode_create(void *data)
{
	AvlNode_t *node = NULL;

	if ((node = malloc(sizeof(AvlNode_t))) == NULL)
	{
		printf("%s, %d: malloc failed.\n", __FUNCTION__, __LINE__);
		return NULL;
	}

	init_avl_node(node);	
	node->data = data;

	return node;
}

AvlNode_t* avlnode_insert(AvlTree_t *tree, AvlNode_t **root, void *data)
{
	assert(tree != NULL);

	if (*root == NULL)
	{
		if ((*root = avlnode_create(data)) == NULL)		
		{
			printf("%s, %d: avlnode_create failed.", __FUNCTION__, __LINE__);
			return NULL;
		}
	}
	else if(tree->cmp_fn(data, (*root)->data) < 0)
	{	
		if (((*root)->left = avlnode_insert(tree, &((*root)->left), data)) == NULL)
		{
			return NULL;
		}
		if ((avl_node_height((*root)->left) - avl_node_height((*root)->right)) > 1)
		{
			if (tree->cmp_fn(data, (*root)->left->data) < 0)
			{
				*root = left_left_rotation(*root);
			}
			else
			{
				*root = left_right_rotation(*root);
			}
		}
	}
	else if(tree->cmp_fn(data, (*root)->data) > 0)	
	{
		if (((*root)->right = avlnode_insert(tree, &((*root)->right), data)) == NULL)
		{
			return NULL;
		}
		if ((avl_node_height((*root)->right) - avl_node_height((*root)->left)) > 1)
		{
			if (tree->cmp_fn(data, (*root)->right->data) < 0) 
			{
				*root = right_left_rotation(*root);
			}
			else
			{
				*root = right_right_rotation(*root);
			}
		}
	}
	else
	{
		printf("%s, %d: avl node has exsited.\n", __FUNCTION__, __LINE__);
		return NULL;
	}

	(*root)->height = max(avl_node_height((*root)->left), avl_node_height((*root)->right)) + 1;

	return *root;
}

void avltree_preorder(AvlTree_t *tree, AvlNode_t *root)
{
	assert(tree->iter_fn != NULL);

	if (root != NULL)
	{
		tree->iter_fn(root->data);
		avltree_preorder(tree, root->left);
		avltree_preorder(tree, root->right);
	}
}

void avltree_inorder(AvlTree_t *tree, AvlNode_t *root)
{
	assert(tree->iter_fn != NULL);

	if (root != NULL)
	{
		avltree_inorder(tree, root->left);
		tree->iter_fn(root->data);
		avltree_inorder(tree, root->right);
	}
}

void avltree_postorder(AvlTree_t *tree, AvlNode_t *root)
{
	assert(tree->iter_fn != NULL);

	if (root != NULL)
	{
		avltree_postorder(tree, root->left);	
		avltree_postorder(tree, root->right);
		tree->iter_fn(root->data);
	}
}

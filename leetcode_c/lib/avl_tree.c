#include "avl_tree.h"

AvlTree_t* avltree_create(AvlCmpFn_t cmp_fn, AvlIterFn_t iter_fn, AvlFreeFn_t free_fn)
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
	tree->free_fn = free_fn;

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
	assert((tree != NULL) && (tree->cmp_fn != NULL));

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

AvlNode_t* avltree_min(AvlNode_t *root)
{
	if (root == NULL)
	{
		return NULL;
	}

	AvlNode_t *n = root;
	while(n->left)	
	{
		n = n->left;
	}

	return n;
}

AvlNode_t* avltree_max(AvlNode_t *root)
{
	if (root == NULL)
	{
		return NULL;
	}

	AvlNode_t *n = root;
	while(n->right)
	{
		n = n->right;
	}

	return n;
}

AvlNode_t* avlnode_delete(AvlTree_t *tree, AvlNode_t **root, void *data)
{
	if ((tree == NULL)  || (root == NULL) || (*root == NULL) || (data == NULL))
	{
		return NULL;
	}

	assert((tree->cmp_fn != NULL) && (tree->free_fn != NULL));

	if (tree->cmp_fn(data, (*root)->data) < 0)
	{
//printf("%s, %d: case 1-1\n", __FUNCTION__, __LINE__);
		(*root)->left = avlnode_delete(tree, &((*root)->left), data);
		if ((avl_node_height((*root)->right) - avl_node_height((*root)->left)) > 1)
		{
//printf("%s, %d: case 1-2\n", __FUNCTION__, __LINE__);
			AvlNode_t *r = (*root)->right;
			if (avl_node_height(r->left) > avl_node_height(r->right))
			{
//printf("%s, %d: case 1-3\n", __FUNCTION__, __LINE__);
				*root = right_left_rotation(*root);
			}
			else
			{
//printf("%s, %d: case 1-4\n", __FUNCTION__, __LINE__);
				*root = right_right_rotation(*root);
			}
		}
	}
	else if (tree->cmp_fn(data, (*root)->data) > 0)
	{
//printf("%s, %d: case 2-1\n", __FUNCTION__, __LINE__);
		(*root)->right = avlnode_delete(tree, &((*root)->right), data);
		if ((avl_node_height((*root)->left) - avl_node_height((*root)->right)) > 1)
		{
//printf("%s, %d: case 2-2\n", __FUNCTION__, __LINE__);
			AvlNode_t *l = (*root)->left;
			if (avl_node_height(l->left) > avl_node_height(l->right))
			{
//printf("%s, %d: case 2-3\n", __FUNCTION__, __LINE__);
				*root = left_left_rotation(*root);
			}
			else
			{
//printf("%s, %d: case 2-4\n", __FUNCTION__, __LINE__);
				*root = left_right_rotation(*root);
			}
		}
	}
	else
	{
//printf("%s, %d: case 3-1\n", __FUNCTION__, __LINE__);
		if ((*root)->left && (*root)->right)
		{
//printf("%s, %d: case 3-2\n", __FUNCTION__, __LINE__);
			if (avl_node_height((*root)->left) > avl_node_height((*root)->right))
			{
//printf("%s, %d: case 3-3\n", __FUNCTION__, __LINE__);
				AvlNode_t *max = avltree_max((*root)->left);
				void *temp = NULL;
				temp = (*root)->data;
				(*root)->data = max->data;
				max->data = temp;
				(*root)->left = avlnode_delete(tree, &((*root)->left), max->data);	
			}
			else
			{
//printf("%s, %d: case 3-4\n", __FUNCTION__, __LINE__);
				AvlNode_t *min = avltree_min((*root)->right);
				void *temp = NULL;
				temp = (*root)->data;
				(*root)->data = min->data;
				min->data = temp;
				(*root)->right = avlnode_delete(tree, &((*root)->right), min->data);
			}
		}
		else
		{
//printf("%s, %d: case 3-5\n", __FUNCTION__, __LINE__);
			AvlNode_t *n = *root;
			*root = (*root)->left ? (*root)->left : (*root)->right;
			tree->free_fn(&n);
		}
	}

	if (*root != NULL)
	{
		(*root)->height = max(avl_node_height((*root)->left), avl_node_height((*root)->right)) + 1;
	}

	return *root;
}

void avltree_destory(AvlTree_t *tree, AvlNode_t **root)
{
	if ((tree != NULL) && (root != NULL) && (*root != NULL))
	{
		avltree_destory(tree, &((*root)->left));
		avltree_destory(tree, &((*root)->right));
		tree->free_fn(root);
	}	
}

AvlNode_t* avltree_search(AvlTree_t *tree, void *data)
{
	assert((tree != NULL) && (tree->cmp_fn != NULL) && (data != NULL));

	AvlNode_t *n = tree->root;
	while (n != NULL)	
	{
		if (tree->cmp_fn(data, n->data) == 0)
		{
			return n;	
		}
		else if(tree->cmp_fn(data, n->data) < 0)
		{
			n = n->left;
		}
		else
		{
			n = n->right;
		}
	}
	return NULL;
}

void avltree_preorder(AvlTree_t *tree, AvlNode_t *root)
{
	assert((tree != NULL) && (tree->iter_fn != NULL));

	if (root != NULL)
	{
		tree->iter_fn(root);
		avltree_preorder(tree, root->left);
		avltree_preorder(tree, root->right);
	}
}

void avltree_inorder(AvlTree_t *tree, AvlNode_t *root)
{
	assert((tree != NULL) && (tree->iter_fn != NULL));

	if (root != NULL)
	{
		avltree_inorder(tree, root->left);
		tree->iter_fn(root);
		avltree_inorder(tree, root->right);
	}
}

void avltree_postorder(AvlTree_t *tree, AvlNode_t *root)
{
	assert((tree != NULL) && (tree->iter_fn != NULL));

	if (root != NULL)
	{
		avltree_postorder(tree, root->left);	
		avltree_postorder(tree, root->right);
		tree->iter_fn(root);
	}
}

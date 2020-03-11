package BinaryTree;

import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Stack;

public class TraverseBinaryTree {
    TreeNode rootNode;

    TraverseBinaryTree() {
        rootNode = initBinaryTree();
    }

    static class TreeNode {
        TreeNode left;
        TreeNode right;
        int value;

        TreeNode(TreeNode left, TreeNode right, int value) {
            this.left = left;
            this.right = right;
            this.value = value;
        }

    }

    private TreeNode initBinaryTree () {
        TreeNode treeNode8 = new TreeNode(null, null, 8);
        TreeNode treeNode9 = new TreeNode(null, null, 9);
        TreeNode treeNode10 = new TreeNode(null, null, 10);
        TreeNode treeNode4 = new TreeNode(null, treeNode8, 4);
        TreeNode treeNode5 = new TreeNode(null, null, 5);
        TreeNode treeNode6 = new TreeNode(treeNode9, treeNode10, 6);
        TreeNode treeNode7 = new TreeNode(null, null, 7);

        TreeNode treeNode2 = new TreeNode(treeNode4, treeNode5, 2);
        TreeNode treeNode3 = new TreeNode(treeNode6, treeNode7, 3);
        
        TreeNode treeNode1 = new TreeNode(treeNode2, treeNode3, 1);

        return treeNode1;
    }

    public void dfsByRecurisve(TreeNode treeNode) {
        if (treeNode == null) {
            return;
        }


        System.out.print("--> " + treeNode.value);
        dfsByRecurisve(treeNode.left);
        dfsByRecurisve(treeNode.right);
    }

    public void bfsByStack (TreeNode rootNode) {
        Stack<TreeNode> stackNodes = new Stack<>();
        
        stackNodes.push(rootNode);

        while (!stackNodes.isEmpty()) {
            TreeNode node = stackNodes.pop();
            System.out.print("--> " + node.value);
            if (node.right != null) {
                stackNodes.push(node.right);
            }
            if (node.left != null) {
                stackNodes.push(node.left);
            }
        }
    }

    public void wfs(TreeNode rootNode) {
        Queue<TreeNode> queueNodes = new  ArrayDeque<>();

        queueNodes.add(rootNode);

        while (!queueNodes.isEmpty()) {
            TreeNode topNode = queueNodes.poll(); 
            System.out.print("--> " + topNode.value);

            if (topNode.left != null) {
                queueNodes.add(topNode.left);
            }

            if (topNode.right != null) {
                queueNodes.add(topNode.right);
            }          
        }
    }

    public static void main (String[] args) {
        TraverseBinaryTree traverseTree = new TraverseBinaryTree();

        traverseTree.dfsByRecurisve(traverseTree.rootNode);
        System.out.println("\n-----------divider-------------");

        traverseTree.bfsByStack(traverseTree.rootNode);
        
        
        System.out.println("\n-----------divider-------------");
        traverseTree.wfs(traverseTree.rootNode);
        System.out.println("");

    }


}
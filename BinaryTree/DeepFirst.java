package BinaryTree;

import java.util.Stack;

public class DeepFirst {
    TreeNode rootNode;

    DeepFirst() {
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
            System.out.println("return ,node is null");
            return;
        }


        System.out.println("Node: " + treeNode.value);
        dfsByRecurisve(treeNode.left);
        dfsByRecurisve(treeNode.right);
    }

    public void bfsByStack (TreeNode rootNode) {
        Stack<TreeNode> stackNode = new Stack<>();
        
        stackNode.push(rootNode);

        while (!stackNode.isEmpty()) {
            TreeNode node = stackNode.pop();
            System.out.println("Node: " + node.value);
            if (node.right != null) {
                stackNode.push(node.right);
            }
            if (node.left != null) {
                stackNode.push(node.left);
            }
        }
    }

    public static void main (String[] args) {
        DeepFirst deepFirst = new DeepFirst();

        deepFirst.dfsByRecurisve(deepFirst.rootNode);

        deepFirst.bfsByStack(deepFirst.rootNode);
    }


}
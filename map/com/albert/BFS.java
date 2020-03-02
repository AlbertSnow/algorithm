package map.com.albert;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.HashMap;

import java.util.List;
import java.util.Map;
import java.util.Queue;

public class BFS {

    public BFS() {
        
    }

    public Map<String, List<String>> initMap () {
        final Map<String, List<String>> map = new HashMap<>(6);

        map.put("S", Arrays.asList(new String[] { "a", "c" }));
        map.put("a", Arrays.asList(new String[] { "F", "b", "d" }));
        map.put("b", Arrays.asList(new String[] {}));
        map.put("c", Arrays.asList(new String[] {"d", "F" }));
        map.put("d", Arrays.asList(new String[] {"F"}));
        map.put("F", Arrays.asList(new String[] {}));

        return map;
    }

    public static void main(final String[] args) {
        final BFS bfs = new BFS();
        final Map<String, List<String>> map = bfs.initMap();

        final Deque<String> findQueue = new ArrayDeque<>();
        final Deque<String> printQueue = new ArrayDeque<>();

        findQueue.add("S");
        String item = null;
        List<String> childItemList = null;

        while ((item = findQueue.poll()) != null && !item.equals("")) {
            printQueue.add(item);
            childItemList = map.get(item);

            if (childItemList == null || childItemList.equals("")) {
                printQueue.pollLast();
            } else {
                findQueue.addAll(childItemList);
            }

            if (childItemList.contains("F")) {
                printQueue.add("F");
                bfs.print(printQueue);
                printQueue.pollLast();
            }
        }
    }

    private void print(final Queue<String> printQueue) {
        System.out.println("Success");

        if (printQueue instanceof ArrayDeque) {
            final ArrayDeque<String> copyQueue = ((ArrayDeque) printQueue).clone();
                        
            String top = null;
            while ((top = copyQueue.poll()) != null) {
                System.out.println("Item: " + top);
            }
        }
    }



}

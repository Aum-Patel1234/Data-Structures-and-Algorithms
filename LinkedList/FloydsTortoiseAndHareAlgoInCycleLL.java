package LinkedList;


public class FloydsTortoiseAndHareAlgoInCycleLL extends LL{
    class Solution {
        public Node detectCycle(Node head) {
            if (head == null || head.next == null) {
                return null;
            }

            Node slow = head;
            Node fast = head;

            while (fast != null && fast.next != null) {
                slow = slow.next;
                fast = fast.next.next;

                if (slow == fast) {
                    Node start = head;

                    while (start != slow) {
                        start = start.next;
                        slow = slow.next;
                    }

                    return start;
                }
            }

            return null;
        }
    }

}

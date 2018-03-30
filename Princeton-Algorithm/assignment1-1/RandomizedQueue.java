import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdOut;
import java.util.Iterator;
public class RandomizedQueue<Item> implements Iterable<Item> {
    private class Node {
        private Node next;
        private Item val;
        private Node(){
            next = null;
        }
        private Node(Item item){
            val = item;
            next = null;
        }
    }
   private Node first;
   private Node last;
   private int len;
   public RandomizedQueue()                 // construct an empty randomized queue
   {
       first = last = new Node();
       len = 0;
   }
   public boolean isEmpty()                 // is the randomized queue empty?
   {
       return len == 0;
   }
   public int size()                        // return the number of items on the randomized queue
   {
       return len;
   }
   public void enqueue(Item item)           // add the item
   {
       if(item == null)
           throw new java.lang.IllegalArgumentException();
       len++;
       Node node = new Node(item);
       last.next = node;
       last = last.next;
   }
   public Item dequeue()                    // remove and return a random item
   {
       if(len == 0)
           throw new java.util.NoSuchElementException();
       int idx = StdRandom.uniform(0, len);
       len --;
       Node node = first;
       while(idx-- != 0)
           node = node.next;
       Item item = node.next.val;
       node.next = node.next.next;
       while(node.next != null){
           node = node.next;
       }
       last = node;
       return item;
   }
   public Item sample()                     // return a random item (but do not remove it)
   {
       if(len == 0)
          throw new java.util.NoSuchElementException();
       int idx = StdRandom.uniform(0, len) + 1;
       Node node = first;
       while(idx-- != 0)
           node = node.next;
       Item item = node.val;
       return item;
   }
   private class RanIterator implements Iterator<Item>{
       
       private int cur = 0;
       private Item[] refs;
       public RanIterator(){
            int[] order = StdRandom.permutation(len);
            refs = (Item[]) new Object[len];
            int i = 0;
            for(Node node = first.next; node!= null; node = node.next){
                refs[order[i++]] = node.val;
            }
       }
       public void remove(){
           throw new java.lang.UnsupportedOperationException();
       }
       public Item next(){
           if(cur == refs.length)
               throw new java.util.NoSuchElementException();
           return refs[cur++];
       }
       public boolean hasNext(){
           return cur != len ;
       }
   }
   public Iterator<Item> iterator() {        // return an independent iterator over items in random order
       return new RanIterator();
   }
   public static void main(String[] args)   // unit testing (optional)
   {
       RandomizedQueue<Integer> rq = new RandomizedQueue<>();
       for(int i = 0; i < 8; i++)
           rq.enqueue(i);
       for(Iterator<Integer> it = rq.iterator(); it.hasNext(); ){
           StdOut.println(it.next());
       }
   }
}
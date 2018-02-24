import java.util.Iterator;
import edu.princeton.cs.algs4.StdOut;
public class Deque<Item> implements Iterable<Item> {
   private Item[] items;
   int head;
   int tail;
   public Deque()                           // construct an empty deque
   {
       head = 1;
       tail = 0;
       items = (Item[]) new Object[256];
   }
   public boolean isEmpty()                 // is the deque empty?
   {
       return size() == 0;
   }
   public int size()                        // return the number of items on the deque
   {
       return (head - 1 - tail + items.length)%items.length;
   }
   private boolean isFull()
   {
       int newh = (head + 1) % items.length;
       return newh == tail;
   }
   private void reSize(){
       StdOut.println(head+","+tail);
       int capacity = 2 * items.length;
       Item[] newitem = (Item[]) new Object[capacity];
       int start = (tail + 1 + items.length) % items.length;
       int i  = 1;
       while(start != head){
           newitem[i++] = items[start];
           start = (start + 1 + items.length) % items.length;
       }
       items = newitem;
       tail = 0;
       head = i;
   }
   public void addFirst(Item item)          // add the item to the front
   {
       if(item == null)
           throw new java.lang.IllegalArgumentException();
       if(isFull())
           reSize();
       items[head] = item;
       head = (head + 1) % items.length;
       
   }
   public void addLast(Item item)           // add the item to the end
   {
       if(item == null)
           throw new java.lang.IllegalArgumentException();
       if(isFull())
           reSize();
       items[tail] = item;
       tail = (tail - 1 + items.length) % items.length;
   }
   public Item removeFirst()                // remove and return the item from the front
   {
       if(isEmpty())
           throw new java.util.NoSuchElementException();
       head = (head - 1 + items.length) % items.length;
       return items[head];
   }
   public Item removeLast()                 // remove and return the item from the end
   {
       if(isEmpty())
           throw new java.util.NoSuchElementException();
       tail = (tail + 1 ) % items.length;
       return items[tail];
   }
   private class DequeIterator implements Iterator<Item>{
       private int index = (head - 1 + items.length) % items.length;
       public boolean hasNext(){
           return index != tail;
       }
       public void remove(){
           throw new java.lang.UnsupportedOperationException();
       }
       public Item next(){
           if(index  == tail)
               throw new java.util.NoSuchElementException();
           Item item = items[index];
           index = ( index  - 1 + items.length ) % items.length;
           return item;
       }
   }
   public Iterator<Item> iterator()         // return an iterator over items in order from front to end
   {
       return new DequeIterator();
   }
   public static void main(String[] args)   // unit testing (optional)
   {
       Deque<Integer> deque = new Deque<>();
       for(int i = 0; i < 255; i++){
           if(i % 2 == 0)
               deque.addFirst(i);
           else
               deque.addLast(i);
       }
       Iterator<Integer> it = deque.iterator(); 
       StdOut.println(deque.size());
       while(it.hasNext()){
           StdOut.print(it.next()+",");
       }
   }
}
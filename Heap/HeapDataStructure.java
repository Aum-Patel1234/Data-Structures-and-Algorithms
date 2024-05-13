import java.util.ArrayList;
import java.util.List;


public class HeapDataStructure {
    public static void main(String[] args) throws Exception {
        int[] arr = {76, 34, 45, 22, 89, 12, 5, 17, 63, 29};

        Heap<Integer> heap = new Heap<>();
        for (int i : arr) {
            heap.insert(i);
        }

//        System.out.println(heap.remove());
        ArrayList<Integer> list = heap.heapSort();
        System.out.println(list);

    }
}

class Heap<T extends Comparable<T>>{
    private List<T> list;
    Heap(){
        this.list = new ArrayList<>();
    }
    private void swap(int first,int second){
        T temp = list.get(first);
        list.set(first, list.get(second));
        list.set(second, temp);
    }

    // parent = i/2
    private int parent(int i){
        return (i - 1) / 2;
    }

    // left = 2*i + 1

    private int leftIndex(int i){
        return 2 * i + 1;
    }

    // right = 2*i + 2

    private int rightIndex(int i){
        return 2 * i + 2;
    }


    public void insert(T element){
        list.add(element);
        upheap(list.size()-1); // passing index of the recently added element
    }
    private void upheap(int index){
        int parent = parent(index);       // finding parent of element

        if(index == 0){
            return;
        }

        if(list.get(parent).compareTo(list.get(index)) > 0){
            swap(index,list.indexOf(list.get(parent)));
            upheap(parent);
        }

    }

    public T remove() throws Exception{
        if(list.isEmpty()){
            throw new Exception("List is Empty can't remove anything");
        }

        T element = list.get(0);
        T last = list.remove(list.size()-1);

        if (!list.isEmpty()) {
            list.set(0, last);
            downheap(0);
        }

        return element;
    }
    private void downheap(int index){
        int min = index;
        int left = leftIndex(index);
        int right = rightIndex(index);

        if(left < list.size() && list.get(min).compareTo(list.get(left)) > 0) {
            min = left;
        }

        if(right < list.size() && list.get(min).compareTo(list.get(right)) > 0) {
            min = right;
        }

        if(min != index) {
            swap(min, index);
            downheap(min);
        }


    }

    public ArrayList<T> heapSort() throws Exception{
        ArrayList<T> data = new ArrayList<>();

        while (!list.isEmpty()){
            data.add(remove());
        }

        return data;
    }

}
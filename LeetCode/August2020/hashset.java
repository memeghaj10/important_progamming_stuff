class MyHashSet {

    /** Initialize your data structure here. */
    
    
    boolean array[];
    
    public MyHashSet() {
        this.array = new boolean[100];
        
    }
    
    public void add(int key) {
        
        if(key>=array.length) {
            extendArray(key);
        }
        
        array[key] = true;
        
    }
    
    public void remove(int key) {
        if(key>=array.length) {
            return ;
        }
        
        array[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        
         if(key>=array.length) {
            return false;
        }
        return array[key];
        
    }
    
    private void extendArray(int key) {
        array = Arrays.copyOf(array,key+3);
    }
}
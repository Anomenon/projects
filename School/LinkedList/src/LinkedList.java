public class LinkedList {

    private Node head;

    public LinkedList(String d){
        head = new Node(d);
    }

    public void add(String d){

        Node newNode=new Node(d);

        Node tmp=head;
        while(tmp.next!=null) {
            tmp=tmp.next;
        }

        tmp.next=newNode;
    }

    public void addHead(String d){
        //...
    }

    public int count(){
        //...
        return 0;
    }

}

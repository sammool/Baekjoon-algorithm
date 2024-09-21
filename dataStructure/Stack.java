
public class Stack{

    private int maxSize;
    private int top;
    private int[] stackArr;

    public Stack(int size){
        this.maxSize = size;
        stackArr = new int[size];
        top = -1;
    }

    public void push(int data){
        if(top == maxSize - 1){
            System.out.println("스택이 가득 찼습니다");
            return;
        }
        stackArr[++top] = data;
    }

    public int pop(){
        if(isEmpty()){
            System.out.println("스택이 비어있습니다");
            return -1;
        }
        return stackArr[top--];
    }

    public int peek(){
        if(isEmpty()){
            System.out.println("스택이 비어있습니다");
            return -1;
        }
        return stackArr[top];
    }

    public boolean isEmpty(){
        return top==-1;
    }

    public int size(){
        return top + 1;
    }

    public static void main(String[] args) {
        Stack stack = new Stack(10);

        for(int i=0; i<5; i++){
            stack.push(i+1);
        }
        
        System.out.println("스택 크기: " + stack.size()); // 출력: 5
        System.out.println("맨 위 데이터: " + stack.peek()); // 출력: 5

        System.out.println("Pop한 데이터: " + stack.pop()); // 출력: 5
        System.out.println("Pop한 데이터: " + stack.pop()); // 출력: 4
        System.out.println("스택이 비어있는지 확인: " + stack.isEmpty()); // 출력: false

        while(!stack.isEmpty()){
            System.out.println(stack.pop());
        }
        System.out.println("스택이 비어있는지 확인: " + stack.isEmpty()); // 출력: true
    }
}
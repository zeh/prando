public class NodeAVL {
	Data data;
	NodeAVL left;
	NodeAVL right;
	NodeAVL top;
	int balance;
	
	NodeAVL(Data data) {
		this.setData(data);
		this.setLeft(null);
		this.setRight(null);
		this.setTop(null);
		this.setBalance(0);
	}
	
	public Data getData() {
		return data;
	}

	public void setData(Data data) {
		this.data = data;
	}

	public NodeAVL getLeft() {
		return left;
	}

	public void setLeft(NodeAVL left) {
		this.left = left;
	}

	public NodeAVL getRight() {
		return right;
	}

	public void setRight(NodeAVL right) {
		this.right = right;
	}
	
	public NodeAVL getTop() {
		return top;
	}

	public void setTop(NodeAVL top) {
		this.top = top;
	}

	public int getBalance() {
		return balance;
	}

	public void setBalance(int balance) {
		this.balance = balance;
	}
}

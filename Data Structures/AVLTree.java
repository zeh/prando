public class AVLTree {
	public NodeAVL raiz;
	
	public void addAVL(NodeAVL current, Data data) {
		if(this.raiz == null) {
			this.raiz = new NodeAVL(data);
		
		}else{
			
			if(data.getChave() < current.data.getChave()) {
				
				if(current.getLeft() == null) {
					current.setLeft(new NodeAVL(data));
					current.getLeft().setTop(current);
					checkBalance(current);
				
				}else {
					addAVL(current.getLeft(), data);
				}
			
			}else if(data.getChave() > current.data.getChave()) {
			
				if(current.getRight() == null) {
					current.setRight(new NodeAVL(data));
					current.getRight().setTop(current);
					checkBalance(current);
				
				}else {
					addAVL(current.getRight(), data);
				}
			}else {
				System.out.println("Chave já existente!!");
			}
		}	
	}
	
	public boolean searchAVL(NodeAVL current, int chave) {
		if(current == null) {
			return false;
		}
		
		if(chave == current.getData().getChave()) {
			return true;
		}
		
		return (chave < current.getData().getChave()) ? searchAVL(current.getLeft(), chave):searchAVL(current.getRight(), chave);
	}
	
	public boolean removeAVL(NodeAVL current, int chave) {
		if(current == null) {
			return false;
		}
		
		if(chave == current.getData().getChave()) {
			removeNode(current);
		}
		
		return (chave < current.getData().getChave()) ? removeAVL(current.getLeft(), chave):removeAVL(current.getRight(), chave);
	}

	private void removeNode(NodeAVL nodeR) {
		NodeAVL aux;

		if (nodeR.getLeft() == null || nodeR.getRight() == null) {

			if (nodeR.getTop() == null) {
				this.raiz = null;
				nodeR = null;
				return;
			}
			aux = nodeR;

		} else {
			aux = sucessor(nodeR);
			nodeR.getData().setChave(aux.getData().getChave());
		}

		NodeAVL aux2;
		
		if (aux.getLeft() != null) {
			aux2 = aux.getLeft();
		} else {
			aux2 = aux.getRight();
		}

		if (aux2 != null) {
			aux2.setTop(aux.getTop());
		}

		if (aux.getTop() == null) {
			this.raiz = aux2;
		} else {
			if (aux == aux.getTop().getLeft()) {
				aux.getTop().setLeft(aux2);
			} else {
				aux.getTop().setRight(aux2);
			}
			checkBalance(aux.getTop());
		}
		aux = null;
	}
	
	private NodeAVL sucessor(NodeAVL q) {
		if (q.getRight() != null) {
			NodeAVL r = q.getRight();
			while (r.getLeft() != null) {
				r = r.getLeft();
			}
			return r;
		} else {
			NodeAVL p = q.getTop();
			while (p != null && q == p.getRight()) {
				q = p;
				p = q.getTop();
			}
			return p;
		}
	}
	
	private int altura(NodeAVL atual) {
		if (atual == null) {
			return -1;
		}

		if (atual.getLeft() == null && atual.getRight() == null) {
			return 0;
		
		} else if (atual.getLeft() == null) {
			return 1 + altura(atual.getRight());
		
		} else if (atual.getRight() == null) {
			return 1 + altura(atual.getLeft());
		
		} else {
			return 1 + Math.max(altura(atual.getLeft()), altura(atual.getRight()));
		}
	}
	
	private void setBalance(NodeAVL no) {
		no.setBalance(altura(no.getRight()) - altura(no.getLeft()));
	}
	
	private void checkBalance(NodeAVL atual) {
		setBalance(atual);
		int balanceamento = atual.getBalance();

		if (balanceamento == -2) {

			if (altura(atual.getLeft().getLeft()) >= altura(atual.getLeft().getRight())) {
				atual = rotacaoDireita(atual);

			} else {
				atual = duplaRotacaoEsquerdaDireita(atual);
			}

		} else if (balanceamento == 2) {

			if (altura(atual.getRight().getRight()) >= altura(atual.getRight().getLeft())) {
				atual = rotacaoEsquerda(atual);

			} else {
				atual = duplaRotacaoDireitaEsquerda(atual);
			}
		}

		if (atual.getTop() != null) {
			checkBalance(atual.getTop());
		} else {
			this.raiz = atual;
		}
	}

	private NodeAVL rotacaoEsquerda(NodeAVL inicial) {

		NodeAVL direita = inicial.getRight();
		direita.setTop(inicial.getTop());

		inicial.setRight(direita.getLeft());

		if (inicial.getRight() != null) {
			inicial.getRight().setTop(inicial);
		}

		direita.setLeft(inicial);
		inicial.setTop(direita);

		if (direita.getTop() != null) {

			if (direita.getTop().getRight() == inicial) {
				direita.getTop().setRight(direita);
			
			} else if (direita.getTop().getLeft() == inicial) {
				direita.getTop().setLeft(direita);
			}
		}

		setBalance(inicial);
		setBalance(direita);

		return direita;
	}

	private NodeAVL rotacaoDireita(NodeAVL inicial) {

		NodeAVL esquerda = inicial.getLeft();
		esquerda.setTop(inicial.getTop());

		inicial.setRight(esquerda.getRight());

		if (inicial.getLeft() != null) {
			inicial.getLeft().setTop(inicial);
		}

		esquerda.setRight(inicial);
		inicial.setTop(esquerda);

		if (esquerda.getTop() != null) {

			if (esquerda.getTop().getRight() == inicial) {
				esquerda.getTop().setRight(esquerda);
			
			} else if (esquerda.getTop().getLeft() == inicial) {
				esquerda.getTop().setLeft(esquerda);
			}
		}

		setBalance(inicial);
		setBalance(esquerda);

		return esquerda;
	}

	private NodeAVL duplaRotacaoEsquerdaDireita(NodeAVL inicial) {
		inicial.setLeft(rotacaoEsquerda(inicial.getLeft()));
		return rotacaoDireita(inicial);
	}

	private NodeAVL duplaRotacaoDireitaEsquerda(NodeAVL inicial) {
		inicial.setRight(rotacaoDireita(inicial.getRight()));
		return rotacaoEsquerda(inicial);
	}

}

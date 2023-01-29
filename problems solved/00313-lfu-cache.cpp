class LFUCache {
public:
    struct Node {
        int key,val,fre,timeStamp;
        Node(): key(-1), val(-1), timeStamp(-1), fre(0) {}
        Node(int k, int v, int ts): key(k), val(v), timeStamp(ts), fre(1) {}
    };

    LFUCache(int capacity) {
        Cap = capacity;
        Node* dummy = new Node();
        pq.push_back(dummy); 
        ts = 0;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        int index = mp[key];
        int val = pq[index]->val;
	pq[index]->fre++;
	pq[index]->timeStamp = ++ts;
        sink(index);
        return val;
    }
    
    void put(int key, int value) {
        if(Cap <= 0) return;
	if(mp.count(key)) {
	   int index = mp[key];
	   pq[index]->val = value;
	   get(key);
	}
	else {
	    if(pq.size() - 1 == Cap) {
	        int oldKey = pq[1]->key;
		mp.erase(oldKey);
		Node* newnode = new Node(key, value, ++ts);
		pq[1] = newnode;
		mp[key] = 1;
		sink(1);
	    }
	    else {
	        Node* newnode = new Node(key, value, ++ts);
		pq.push_back(newnode);
		mp[key] = pq.size() - 1;
		swim(pq.size() - 1);
	    }
	}
    }
    
private:
	vector<Node*> pq; 
	unordered_map<int, int> mp; 
	int Cap;
	int ts; 
	void sink(int index) {
	    int left = 2 * index, right = 2 * index + 1, target = index;
	    if(left < pq.size() && pq[left]->fre <= pq[target]->fre)
               target = left;
            if(right < pq.size()) { 
                if(pq[right]->fre < pq[target]->fre || (pq[right]->fre == pq[target]->fre && pq[right]->timeStamp < pq[target]->timeStamp)) 
                     target = right;
		}
		if(target != index) {
		    myswap(target, index);
	            sink(target);
		}
	}
	void swim(int index) {
	    int par = index / 2;
	    while(par > 0 && pq[par]->fre > pq[index]->fre) {
	        myswap(par, index);
		index = par;
		par /= 2;
	    }
	}

	void myswap(int id1, int id2) {
	    swap(pq[id1], pq[id2]);
	    mp[pq[id1]->key] = id1;
	    mp[pq[id2]->key] = id2;
	}
};
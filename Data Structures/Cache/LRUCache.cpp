// Least recently used (LRU) cache (https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU)
// Discards the least recently used items first


#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <list>

struct LRUCacheItem {
  LRUCacheItem(int timestamp, int key): key(key), timestamp(timestamp) {}

  int timestamp;
  int key;
};

struct LRUCacheComp {
  bool operator()(const auto & item1,
    const LRUCacheItem & item2) {
    return item1.timestamp < item2.timestamp;
  }
};

class LRUCache {
  public:
    LRUCache(int capacity) {
      this -> capacity = capacity;
    }

  int get(int key) {
    auto itCache = cache.find(key);

    if (itCache != cache.end()) {
      this->addToRecentUsed(key);
      return itCache->second;
    }

    return -1;
  }

  void put(int key, int value) {

    cache[key] = value;

    this->addToRecentUsed(key);

    invalidateCache();
  }
  private:
    void addToRecentUsed(int key) {
      auto itRecentUsedLocation = recentUsedLocation.find(key);
      if (itRecentUsedLocation != recentUsedLocation.end()) { //If exists
        //erase old
        recent_used.erase(itRecentUsedLocation->second);
      }

      //create new
      recent_used.push_back(key);
      auto it = recent_used.end();
      --it;
      //save location
      recentUsedLocation[key] = it;

    }
  void invalidateCache() {
    if (cache.size() > capacity) {
      int keyToRemove = recent_used.front();

      cache.erase(keyToRemove);
      recent_used.pop_front();
      recentUsedLocation.erase(keyToRemove);
    }
  }
  std::unordered_map < int, int > cache;

  std::list < int > recent_used;
  std::unordered_map < int, std::list < int > ::iterator > recentUsedLocation;

  int capacity;
};

int main() {
	LRUCache cache(2 /* capacity */);

	cache.put(1, 1);
	cache.put(2, 2);
	std::cout << "> Get(1) = " << cache.get(1) << std::endl;       // returns 1
	cache.put(3, 3);    // evicts key 2
	std::cout <<"> Get(2) = " << cache.get(2) << std::endl;       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	std::cout <<"> Get(1) = " <<cache.get(1) << std::endl;       // returns -1 (not found)
	std::cout <<"> Get(3) = " <<cache.get(3) << std::endl;       // returns 3
	std::cout <<"> Get(4) = " <<cache.get(4) << std::endl;       // returns 4
}
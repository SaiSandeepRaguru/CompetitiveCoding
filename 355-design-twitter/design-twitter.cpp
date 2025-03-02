class Tweet{
    

public:
    int tweetId;
    int timestamp;
    int userId;
    Tweet(int _id,int _time,int _user){
        tweetId = _id;
        timestamp = _time;
        userId = _user;
    }
};

class User{
    

public:
    int userId;
    unordered_set<User*> follows;
    unordered_set<Tweet*> tweets;
    User(int _id){
        userId = _id;
    }
};

struct comparator{
    bool operator()(Tweet* a,Tweet* b){
        return a->timestamp>b->timestamp;
    }
};

class Twitter {
public:
    int time;
    unordered_map<int,User*> users;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        Tweet* tweet = new Tweet(tweetId,time,userId);
        if(users.find(userId)==users.end()){
            users[userId] = new User(userId);
        }
        users[userId]->tweets.insert(tweet);
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet*,vector<Tweet*>,comparator> pq;
        if(users.find(userId)==users.end()){
            return {};
        }
        User* user = users[userId];
        for(Tweet* t: user->tweets){
            pq.push(t);
            if(pq.size()>10){
                pq.pop();
            }
        }
        for(User* u: user->follows){
            for(Tweet* t: u->tweets){
                pq.push(t);
                if(pq.size()>10){
                    pq.pop();
                }
            }
        }
        vector<int> res; 
        while(!pq.empty()){
            res.push_back(pq.top()->tweetId); pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(users.find(followerId)==users.end()){
            users[followerId] = new User(followerId);
        }
        if(users.find(followeeId)==users.end()){
            users[followeeId] = new User(followeeId);
        }
        users[followerId]->follows.insert(users[followeeId]);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(users[followerId]->follows.find(users[followeeId])!=users[followerId]->follows.end()){
            users[followerId]->follows.erase(users[followeeId]);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
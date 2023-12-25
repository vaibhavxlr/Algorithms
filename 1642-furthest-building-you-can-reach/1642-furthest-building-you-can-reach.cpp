class Solution
{
    public:
        int furthestBuilding(vector<int> &heights, int bricks, int ladders)
        {
            priority_queue<int> pq;
            
            for (int i = 1; i < heights.size(); i++)
            {
              int diff = heights[i] - heights[i - 1];
              if(diff > 0) {
                  if(bricks >= diff) {
                      bricks -= diff;
                      pq.push(diff);
                  } else {
                      if(ladders > 0) {
                         if(pq.size() > 0 && pq.top() > diff) {
                            bricks += pq.top();
                            bricks -= diff;
                            pq.push(diff);
                            pq.pop();
                         }
                         ladders--;
                      } else {
                          return i - 1;
                      }
                  }
              }
            }
            return heights.size() - 1;
        }
};
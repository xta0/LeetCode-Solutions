class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var map = [Int:Int]();
        var result = [Int]();
        for(i, item ) in nums.enumerated(){
            map[item]=i;
        }
        for(j,item) in nums.enumerated(){
            let x = target-item;
            if let index = map[x]{
                if(index != j){
                    result.append(j);
                    result.append(index);
                    break;
                }
            }
        }
        return result;
    }
}

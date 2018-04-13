# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
    map = {}
    result = []
    nums.each_with_index do |item, index|
        map[item] = index
    end
    nums.each_with_index do |item, index|
        x = target - item
        if map.has_key?(x)
            index_x = map[x]
            if index_x != index
                result<<index
                result<<index_x
                break
            end
        end
    end
    result
end

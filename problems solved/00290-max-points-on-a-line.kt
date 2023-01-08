class Solution {
    fun maxPoints(points: Array<IntArray>): Int {
        var res:Int = 0
        for(firstPoint in points){
            val slopes_map = hashMapOf<Double, Int>()
            for(secondPoint in points){
                if(secondPoint == firstPoint){
                    continue;
                }
                val slope: Double = if(secondPoint[0]-firstPoint[0] != 0){
                    (secondPoint[1]-firstPoint[1]).toDouble()/(secondPoint[0]-firstPoint[0]).toDouble();
                }else{
                    Double.MAX_VALUE
                }
                if(slopes_map.containsKey(slope)){
                    slopes_map.put(slope,slopes_map.get(slope)?.plus(1)!!)
                } else{
                    slopes_map.put(slope,1)
                }
            }
            var maxSlopePoints=0;
            for(value in slopes_map.values){
                maxSlopePoints = maxOf(maxSlopePoints, value)
            }
            res = maxOf(res,maxSlopePoints+1)
        }
        return res
    }
}
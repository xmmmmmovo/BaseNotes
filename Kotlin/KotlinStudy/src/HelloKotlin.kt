fun main(args: Array<String>) {

    var array = intArrayOf(1, 2, 3, 4, 5)

    for (item in array) {
        println(item)
    }

    for (i in array.indices) {
        println(i)
    }

    for ((k, v) in array.withIndex()) {
        println("$k, $v")
    }
}
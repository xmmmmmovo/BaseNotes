fun main(args: Array<String>) {

    var array = listOf<String>(
        "hello", "world", "hello world", "welcome", "goodbye"
    )

    when {
        "world" in array -> println("world in array")
    }

    array
        .filter {
            it.length > 5
        }
        .map {
            it.toUpperCase()
        }
        .sorted()
        .forEach {
            println(it)
        }


}
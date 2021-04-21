import java.io.File
import java.util.*

fun outputVars(varTable: Map<String, Int>) {
    varTable.forEach { k, v ->
        println("$k $v")
    }
}

fun exec(sq: Sequence<String>) {
    val varmap = mutableMapOf<String, Int>()
    val jmpstack = 0

    sq
        .take(100)
        .map { s -> s.split(' ') }
        .forEach { input: List<String> ->
            if (jmpstack > 0) return
            when (input[0]) {
                "mov" -> {
                    varmap[input[1]] = input[2]
                        .toIntOrNull() ?: varmap[input[2]]!!
                }
                "inc" -> {
                    varmap.merge(input[1], 1, Int::plus)
                }
                "dec" -> {
                    varmap.merge(input[1], -1, Int::plus)
                }
                "jnz" -> {
                    if (varmap[input[1]]!! != 0) jmpstack += input[2].toInt()
                }
            }
        }
}

fun main(args: Array<String>) {
    File("a.txt").useLines { exec(it) }
    File("b.txt").useLines { exec(it) }
}
import java.io.FileReader
import java.io.FileWriter
 
class DFA(sigma: CharArray, q: IntRange, private val s: Int, private val t: IntArray, private val delta: Map<Pair<Int, Char>, Int>) {
    init {
        assert(s in q)
        for (x in t) assert(x in q)
        for (key in delta.keys) {
            assert(key.first in q)
            assert(key.second in sigma)
            assert(delta[key]!! in q)
        }
    }
 
    fun accept(str: String): Boolean {
        var cur: Int = s
        for (c in str) {
            cur = delta[Pair(cur, c)] ?: return false
        }
        return cur in t
    }
}
 
fun getDFA(n: Int, t: IntArray, delta: Map<Pair<Int, Char>, Int>) = DFA(CharArray(26) { i -> (Char(i + 'a'.code)) }, 1..n, 1, t, delta)
 
fun main() {
    val sc = java.util.Scanner(FileReader("problem1.in"))
    val out = FileWriter("problem1.out")
    val str = sc.next()
    val n = sc.nextInt()
    val m = sc.nextInt()
    val t = IntArray(sc.nextInt()) { sc.nextInt() }
    val delta = HashMap<Pair<Int, Char>, Int>()
    for (i in 0 until m) {
        val a = sc.nextInt()
        val b = sc.nextInt()
        val c = sc.next()[0]
        delta[Pair(a, c)] = b
    }
    out.write(if (getDFA(n, t, delta).accept(str)) "Accepts" else "Rejects")
    out.close()
}

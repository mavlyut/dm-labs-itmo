import java.io.FileReader
import java.io.FileWriter
import java.util.HashSet as hs
 
class NFA(sigma: CharArray, q: IntRange, private val s: Int, private val t: hs<Int>, private val delta: Map<Pair<Int, Char>, hs<Int>>) {
    private val n: Int = q.count()
 
    init {
        assert(s in q)
        for (x in t) assert(x in q)
        for (key in delta.keys) {
            assert(key.first in q)
            assert(key.second in sigma)
            assert(delta[key]!!.size == n)
        }
    }
 
    fun accept(str: String): Boolean {
//        println(delta)
        var r = HashSet<Int>()
        r.add(s)
        for (i in str.indices) {
            val tmp = HashSet<Int>()
            for (q in r) {
                val x = Pair(q, str[i])
                if (x in delta) {
                    tmp.addAll(delta[x]!!)
                }
            }
//            println(r)
            r = tmp
        }
//        println(r)
        r.retainAll(t)
        return r.size >0
    }
}
 
fun getNFA(n: Int, t: hs<Int>, delta: Map<Pair<Int, Char>, hs<Int>>) =
    NFA(CharArray(26) { i -> (Char(i + 'a'.code)) }, 0 until n, 0, t, delta)
 
fun main() {
    val sc = java.util.Scanner(FileReader("problem2.in"))
    val out = FileWriter("problem2.out")
    val str = sc.next()
    val n = sc.nextInt()
    val m = sc.nextInt()
    val k = sc.nextInt()
    val t = hs<Int>()
    for (i in 0 until k) t.add(sc.nextInt() - 1)
    val delta = HashMap<Pair<Int, Char>, hs<Int>>()
    for (i in 0 until m) {
        val a = sc.nextInt() - 1
        val b = sc.nextInt() - 1
        val c = sc.next()[0]
        val x = Pair(a, c)
        if (x !in delta) delta[x] = hs()
        delta[x]!!.add(b)
    }
    out.write(if (getNFA(n, t, delta).accept(str)) "Accepts" else "Rejects")
    out.close()
}

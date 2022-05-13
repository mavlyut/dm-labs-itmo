import java.io.FileReader
import java.io.FileWriter
import java.util.Scanner
import java.util.Vector as v
import kotlin.Pair as p
 
fun main() {
    val sc = Scanner(FileReader("equivalence.in"))
    val out = FileWriter("equivalence.out")
    out.write(if (solve(sc)) "YES" else "NO")
    out.close()
}
 
class DFA(sc: Scanner) {
    val t: IntArray
    val delta: Array<IntArray>
    val visited: BooleanArray
 
    init {
        val n = sc.nextInt() + 1
        val m = sc.nextInt()
        t = IntArray(sc.nextInt()) { sc.nextInt() }
        delta = Array(n) { IntArray(26) { 0 } }
        visited = BooleanArray(n) { false }
        for (i in 1..m) {
            val a = sc.nextInt()
            val b = sc.nextInt()
            delta[a][sc.next()[0].code - 'a'.code] = b
        }
    }
 
    override fun toString(): String = delta.joinToString("\n") { i -> i.joinToString(" ") }
}
 
fun solve(sc: Scanner): Boolean {
    val q = v<p<Int, Int>>()
    val x = DFA(sc)
    val y = DFA(sc)
    q.add(p(1, 1))
    while (q.isNotEmpty()) {
        val f = q.removeLast()
        if (f.first != 0) x.visited[f.first] = true
        if (f.second != 0) y.visited[f.second] = true
        if (x.t.contains(f.first) != y.t.contains(f.second)) return false
        for (i in 0..25) {
            val u = x.delta[f.first][i]
            val v = y.delta[f.second][i]
            if (!(x.visited[u] && y.visited[v]) && (u != 0 || v != 0)) q.add(p(u, v))
        }
    }
    return true
}

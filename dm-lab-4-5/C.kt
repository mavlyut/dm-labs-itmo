import java.io.FileReader
import java.io.FileWriter
import java.util.*
 
const val MOD = 1_000_000_000 + 7
 
fun main() {
    val sc = Scanner(FileReader("problem3.in"))
    val out = FileWriter("problem3.out")
    out.write(solve(sc).toString())
    out.close()
}
 
fun solve(sc: Scanner): Int {
    val n = sc.nextInt()
    val m = sc.nextInt()
    val k = sc.nextInt()
    val t = IntArray(k) { sc.nextInt() - 1 }
    val g = Array(n) { Vector<Int>() }
    val gRev = Array(n) { Vector<Int>() }
    for (i in 0 until m) {
        val a = sc.nextInt() - 1
        val b = sc.nextInt() - 1
        sc.next()
        g[a].add(b)
        gRev[b].add(a)
    }
    val colour = IntArray(n) { 0 }
    for (i in t) dfs(i, colour, gRev)
    return if (checkInfinity(0, colour, g)) -1 else count(0, colour, g, t)
}
 
fun dfs(v: Int, colour: IntArray, gRev: Array<Vector<Int>>) {
    if (colour[v] > 0) return
    colour[v] = 2
    for (i in gRev[v]) dfs(i, colour, gRev)
    colour[v] = 1
}
 
fun checkInfinity(v: Int, colour: IntArray, g: Array<Vector<Int>>): Boolean {
    if (colour[v] == 0) return false
    if (colour[v] == 2) return true
    colour[v] = 2
    for (i in g[v]) if (checkInfinity(i, colour, g)) {
        colour[v] = 1
        return true
    }
    colour[v] = 1
    return false
}
 
fun count(v: Int, colour: IntArray, g: Array<Vector<Int>>, t: IntArray): Int {
    if (colour[v] == 0) return 0
    var res = if (t.contains(v)) 1 else 0
    for (i in g[v]) res = (res + count(i, colour, g, t)) % MOD
    return res
}

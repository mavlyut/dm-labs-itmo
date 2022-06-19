import java.io.FileReader
import java.io.FileWriter
import java.util.Scanner
import kotlin.collections.HashMap as map
import kotlin.collections.HashSet as set
 
class CFG(private val goodRules: map<Int, map<Char, set<Int>>>, private val badRules: map<Int, set<Char>>, val s: Int) {
    private fun accept(x: String, ind: Int, nt: Int): Boolean {
        if (ind == x.length - 1) {
            return badRules[nt]?.contains(x[ind]) ?: false
        }
        val tmp = goodRules[nt]?.get(x[ind]) ?: return false
        for (ntNew in tmp) {
            if (accept(x, ind + 1, ntNew)) return true
        }
        return false
    }
 
    fun accept(x: String): Boolean = accept(x, 0, s)
}
 
fun main() {
    val sc = Scanner(FileReader("automaton.in"))
    val out = FileWriter("automaton.out")
    val n = sc.nextInt()
    val start = sc.next()[0] - 'A'
    val goodRules = map<Int, map<Char, set<Int>>>()
    val badRules = map<Int, set<Char>>()
    for (i in 0 until n) {
        val nt = sc.next()[0] - 'A'
        sc.next()
        val rhs = sc.next()
        val t = rhs[0]
        if (rhs.length == 1) {
            if (badRules[nt] == null) badRules[nt] = set()
            badRules[nt]!!.add(t)
        } else {
            if (goodRules[nt] == null) goodRules[nt] = map()
            if (goodRules[nt]!![t] == null) goodRules[nt]!![t] = set()
            goodRules[nt]!![t]!!.add(rhs[1] - 'A')
        }
    }
    val a = CFG(goodRules, badRules, start)
    val m = sc.nextInt()
    for (i in 0 until m) {
        out.write(if (a.accept(sc.next())) "yes\n" else "no\n")
    }
    out.close()
}


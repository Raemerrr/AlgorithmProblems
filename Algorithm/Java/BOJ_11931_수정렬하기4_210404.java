import java.io.*;
import java.util.Arrays;
import java.util.Collections;

public class BOJ_11931_수정렬하기4_210404 {
  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    Integer[] input = new Integer[Integer.parseInt(reader.readLine())];
    for (int i = 0; i < input.length; i++) {
      input[i] = Integer.parseInt(reader.readLine());
    }
    Arrays.sort(input, Collections.reverseOrder());
    for (Integer el : input) {
      writer.write(String.valueOf(el) + "\n");
    }
    writer.flush();
  }
}

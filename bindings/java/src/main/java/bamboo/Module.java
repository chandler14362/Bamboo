package bamboo;

/**
 * Created by stowellc17 on 9/9/15.
 */
public final class Module {

    static {
        System.loadLibrary("bamboo");
    }

    private final long _handle;

    private Module(final long handle) {
        _handle = handle;
    }

    public static native Module readDCFile(final String filename);

    public native boolean parseDCFile(final String filename);

    public native long calculateHash();

}
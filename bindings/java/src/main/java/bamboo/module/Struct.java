package bamboo.module;

/**
 * Created by stowellc17 on 9/12/15.
 */
public class Struct {

    private final long _handle;

    private Struct(final long handle) {
        _handle = handle;
    }

    public native int getId();

    public native String getName();

}

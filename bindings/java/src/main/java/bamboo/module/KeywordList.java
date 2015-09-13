package bamboo.module;

/**
 * Created by Chandler on 9/13/2015.
 */
public class KeywordList {

    private final long _handle;

    private KeywordList(final long handle) {
        _handle = handle;
    }

    public native boolean hasKeyword(final String keyword);

    public native int getNumKeywords();

    public native String getKeyword(final int n);

    public native boolean hasMatchingKeywords(final KeywordList other);

    public native void copyKeywords(final KeywordList other);

    public native boolean addKeyword(final String keyword);

}

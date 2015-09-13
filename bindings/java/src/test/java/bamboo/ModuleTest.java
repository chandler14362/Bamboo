package bamboo;

import bamboo.module.Struct;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

/**
 * Created by stowellc17 on 9/9/15.
 */
public class ModuleTest {

    public String getDCPath() {
        boolean windows = System.getProperty("os.name").toLowerCase().startsWith("win");
        String path = getClass().getResource("test_dc.dc").getPath();
        if (windows)
            path = path.substring(1, path.length());
        return path;
    }

    @Test
    public void testReadDCFile() {
        Module module = Module.readDCFile(getDCPath());
        assertEquals(module.calculateHash(), 24861);

        assertEquals(module.getNumKeywords(), 1);
        assertEquals(module.hasKeyword(""), false);
        assertEquals(module.getKeyword(0), "testKeyword");

        assertEquals(module.getNumStructs(), 1);
        Struct struct = module.getStruct(0);
        assertEquals(struct.getName(), "TestStruct");
        assertEquals(struct.getId(), 0);
    }

}

package bamboo;

import bamboo.module.Struct;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

/**
 * Created by stowellc17 on 9/9/15.
 */
public class ModuleTest {

    @Test
    public void testReadDCFile() {
        Module module = Module.readDCFile(getClass().getResource("test_dc.dc").getPath());
        assertEquals(module.calculateHash(), 24861);
        assertEquals(module.getNumStructs(), 1);

        Struct struct = module.getStruct(0);
        assertEquals(struct.getName(), "TestStruct");
        assertEquals(struct.getId(), 0);
    }

}
